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
	//������
	const AVCodec* codec;
	//�����ṹ��
	AVCodecParserContext* parser;
	//�������ýṹ��
	AVCodecContext* c = NULL;

	FILE* f;
	AVFrame* frame;
	//����32��64bit��ȡ�Ż������ӿռ��ֹ��ȡ�Ƿ���ַ��ֵ���μ��궨��ע�ͣ�
	uint8_t inbuf[kBufSize + AV_INPUT_BUFFER_PADDING_SIZE];
	uint8_t *data;
	size_t dataSize;
	int ret;
	//AVPacker�ṹdata�͸�decoders����
	AVPacket *avpkt;
	//����AVPacket�ռ䣨������data�ռ䣩
	avpkt = av_packet_alloc();
	//KBufSize�ڵ�ֵ������¡�ʣ�µĿռ�Ҫ��0
	memset(inbuf + kBufSize, 0, AV_INPUT_BUFFER_PADDING_SIZE);
	//���ҽ�����
	codec = avcodec_find_decoder(AV_CODEC_ID_MPEG1VIDEO);

	parser = av_parser_init(codec->id);
	//���ݽ���������AVCodecContext�ռ�
	c = avcodec_alloc_context3(codec);

	//ժ��ffmpeg example decode_video.c
	/* For some codecs, such as msmpeg4 and mpeg4, width and height
	   MUST be initialized there because this information is not
	   available in the bitstream. */

	/**�򿪽�����*/
	ret = avcodec_open2(c, codec, NULL);
	//�����ƶ�ȡ�ļ�
	f = fopen(fileName, "rb");

	//����AVframe�ṹ��ռ䣨������data�ռ䣩
	frame = av_frame_alloc();

	while (!feof(f))
	{
		//���ļ��ж�ȡһ������
		dataSize = fread(inbuf, 1, kBufSize, f);
		if (!dataSize) break;
		//ʹ��parser �������ݵ� frames
		data = inbuf;
		while (dataSize > 0)
		{
			//����һ��packet
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