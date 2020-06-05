#include "decode.h"

const int kBufSize = 4096;


bool Init()
{
	
}

int OpenCamera(int id)
{

	return 0;
}

int OpenVideo(const char* fileName, const char* outfileName)
{
	//解码器
	const AVCodec* codec;
	//--
	AVCodecParserContext* parser;
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
	//申请AVPacket空间，不申请data空间。
	avpkt = av_packet_alloc();
	//KBufSize内的值，会更新。剩下的空间要置0
	memset(inbuf + kBufSize, 0, AV_INPUT_BUFFER_PADDING_SIZE);
	//查找解码器
	codec = avcodec_find_decoder(AV_CODEC_ID_MPEG1VIDEO);

}