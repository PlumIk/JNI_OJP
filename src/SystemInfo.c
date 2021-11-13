#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
  
JNIEXPORT jstring JNICALL Java_SystemInfo_get_1info
(JNIEnv *env, jobject jobj)
{
   FILE *fp;
  char name[] = "/proc/cpuinfo";
  if ((fp = fopen(name, "r")) == NULL)
  {
    printf("Не удалось открыть файл");
    getchar();
    return 0;
  }
  char* buffer=malloc(256*sizeof(char));
  char a;
  int size=255;
  int sizenow=0;
  while ((a=fgetc(fp))!=EOF){
  	buffer[sizenow]=a;
  	sizenow++;
  	if(sizenow==size){
  		size=size+256;
  		buffer=realloc( buffer, size );
  	}
  	
  }
   return (*env)->NewStringUTF(env,buffer);
   
}
