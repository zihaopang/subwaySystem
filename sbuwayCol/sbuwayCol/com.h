
#ifndef __COM_H__  
#define __COM_H__  


#ifdef __cplusplus  
extern "C" {
#endif   
	//�򿪴���  
	int OpenComPort(int port, int userBaudRate);//�򿪴���  
												//�رմ���  
	void CloseComPort(void);//�رմ���  
	int ReadComBlock(unsigned char *buf, int maxLen);
	void _DoRxTx(void *args);

	int ReadComBuf(unsigned char *buf, int maxLen);//������  
	int WriteComBuf(unsigned char *buf, int maxLen);//д����  
	int WriteComByte(unsigned char byte);//������дһ���ֽ�  
	int ReadComByte(unsigned char byte);//�Ӵ��ڶ�ȡһ���ֽ�  
	void resetComPort(void);//���ô���  
	void resetRTS(void);//resetRTS_sub(150,20);  
	int ReceiveMessage(unsigned char *pBuf, int maxlen, int time);//��ʱ��Ľ��ղ���  
	void resetRTSLowHigh(int Low, int High);//CTS�ߵ͵�ƽ����  
	void SetRTSControlEnable(bool enable);//CTS����:enable=true:����,false:����  
#ifdef __cplusplus  
}
#endif   

#endif  


