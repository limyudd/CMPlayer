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
	//������
	const AVCodec* codec;
	//--
	AVCodecParserContext* parser;
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
	//����AVPacket�ռ䣬������data�ռ䡣
	avpkt = av_packet_alloc();
	//KBufSize�ڵ�ֵ������¡�ʣ�µĿռ�Ҫ��0
	memset(inbuf + kBufSize, 0, AV_INPUT_BUFFER_PADDING_SIZE);
	//���ҽ�����
	codec = avcodec_find_decoder(AV_CODEC_ID_MPEG1VIDEO);

}