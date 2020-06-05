#include "decode.h"

const int kBufSize = 4096;


bool Init()
{
	
}

int OpenCamera(int id)
{

	return 0;
}

static void pgmSave(unsigned char* buf, int wrap, int xSize, int ySize, const char* fileName)
{
	FILE* f = fopen(fileName, "w");
	fprintf(f, "P5\n%d %d\n%d\n", xSize, ySize, 255);
	for (int i = 0; i < ySize; i++)
	{
		fwrite(buf + (i * wrap), 1, xSize, f);
	}
	fclose(f);
}

static void decode(AVCodecContext *decCtx, AVFrame *frame, AVPacket *pkt, const char* fileName)
{
	char buf[1024];
}


int OpenVideo(const char* fileName, const char* outfileName)
{
	//解码器
	const AVCodec* codec;
	//解析结构体
	AVCodecParserContext* parser;
	//参数设置结构体
	AVCodecContext* c = NULL;

	FILE* f;
	AVFrame* frame;
	//存在32、64bit读取优化，增加空间防止读取非法地址的值（参见宏定义注释）
	uint8_t inbuf[kBufSize + AV_INPUT_BUFFER_PADDING_SIZE];
	uint8_t *data;
	size_t dataSize;
	int ret;
	//AVPacker结构data送给decoders解码
	AVPacket *avpkt;
	//申请AVPacket空间（不申请data空间）
	avpkt = av_packet_alloc();
	//KBufSize内的值，会更新。剩下的空间要置0
	memset(inbuf + kBufSize, 0, AV_INPUT_BUFFER_PADDING_SIZE);
	//查找解码器
	codec = avcodec_find_decoder(AV_CODEC_ID_MPEG1VIDEO);

	parser = av_parser_init(codec->id);
	//根据解码器申请AVCodecContext空间
	c = avcodec_alloc_context3(codec);

	//摘自ffmpeg example decode_video.c
	/* For some codecs, such as msmpeg4 and mpeg4, width and height
	   MUST be initialized there because this information is not
	   available in the bitstream. */

	/**打开解码器*/
	ret = avcodec_open2(c, codec, NULL);
	//二进制读取文件
	f = fopen(fileName, "rb");

	//申请AVframe结构体空间（不申请data空间）
	frame = av_frame_alloc();

	while (!feof(f))
	{
		//从文件中读取一行数据
		dataSize = fread(inbuf, 1, kBufSize, f);
		if (!dataSize) break;
		//使用parser 分离数据到 frames
		data = inbuf;
		while (dataSize > 0)
		{
			//解析一个packet
			ret = av_parser_parse2(parser, c, &avpkt->data, &avpkt->size, data, dataSize, AV_NOPTS_VALUE, AV_NOPTS_VALUE, 0);
			if (ret < 0)
			{
				exit(1);
			}
			data += ret;
			dataSize -= ret;
			if (avpkt->size)
			{
				decode();
			}
		}
	}
}