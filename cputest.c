#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>


char output[256][256];

void prepare(void)
{
	memset(output,0,sizeof(output));
	strcat(output[0x00],"Null descriptor, this byte contains no information\n");
	strcat(output[0x01],"Instruction TLB: 4 KByte pages, 4-way set associative, 32 entries\n");
	strcat(output[0x02],"Instruction TLB: 4 MByte pages, fully associative, 2 entries\n");
	strcat(output[0x03],"Data TLB: 4 KByte pages, 4-way set associative, 64 entries\n");
	strcat(output[0x04],"Data TLB: 4 MByte pages, 4-way set associative, 8 entries\n");
	strcat(output[0x05],"Data TLB1: 4 MByte pages, 4-way set associative, 32 entries\n");
	strcat(output[0x06],"1st-level instruction cache: 8 KBytes, 4-way set associative, 32 byte line size\n");
	strcat(output[0x08],"1st-level instruction cache: 16 KBytes, 4-way set associative, 32 byte line size\n");
	strcat(output[0x09],"1st-level instruction cache: 32KBytes, 4-way set associative, 64 byte line size\n");
	strcat(output[0x0A],"1st-level data cache: 8 KBytes, 2-way set associative, 32 byte line size\n");
	strcat(output[0x0B],"Instruction TLB: 4 MByte pages, 4-way set associative, 4 entries\n");
	strcat(output[0x0C],"1st-level data cache: 16 KBytes, 4-way set associative, 32 byte line size\n");
	strcat(output[0x0D],"1st-level data cache: 16 KBytes, 4-way set associative, 64 byte line size\n");
	strcat(output[0x0E],"1st-level data cache: 24 KBytes, 6-way set associative, 64 byte line size\n");
	strcat(output[0x1D],"2nd-level cache: 128 KBytes, 2-way set associative, 64 byte line size\n");
	strcat(output[0x21],"2nd-level cache: 256 KBytes, 8-way set associative, 64 byte line size\n");
	strcat(output[0x22],"3rd-level cache: 512 KBytes, 4-way set associative, 64 byte line size, 2 lines per sector\n");
	strcat(output[0x23],"3rd-level cache: 1 MBytes, 8-way set associative, 64 byte line size, 2 lines per sector\n");
	strcat(output[0x24],"2nd-level cache: 1 MBytes, 16-way set associative, 64 byte line size\n");
	strcat(output[0x25],"3rd-level cache: 2 MBytes, 8-way set associative, 64 byte line size, 2 lines per sector\n");
	strcat(output[0x29],"3rd-level cache: 4 MBytes, 8-way set associative, 64 byte line size, 2 lines per sector\n");
	strcat(output[0x2C],"1st-level data cache: 32 KBytes, 8-way set associative, 64 byte line size\n");
	strcat(output[0x30],"1st-level instruction cache: 32 KBytes, 8-way set associative, 64 byte line size\n");
	strcat(output[0x40],"No 2nd-level cache or, if processor contains a valid 2nd-level cache, no 3rd-level cache\n");
	strcat(output[0x41],"2nd-level cache: 128 KBytes, 4-way set associative, 32 byte line size\n");
	strcat(output[0x42],"2nd-level cache: 256 KBytes, 4-way set associative, 32 byte line size\n");
	strcat(output[0x43],"2nd-level cache: 512 KBytes, 4-way set associative, 32 byte line size\n");
	strcat(output[0x44],"2nd-level cache: 1 MByte, 4-way set associative, 32 byte line size\n");
	strcat(output[0x45],"2nd-level cache: 2 MByte, 4-way set associative, 32 byte line size\n");
	strcat(output[0x46],"3rd-level cache: 4 MByte, 4-way set associative, 64 byte line size\n");
	strcat(output[0x47],"3rd-level cache: 8 MByte, 8-way set associative, 64 byte line size\n");
	strcat(output[0x48],"2nd-level cache: 3MByte, 12-way set associative, 64 byte line size\n");
	strcat(output[0x49],"3rd-level cache: 4MB, 16-way set associative, 64-byte line size (Intel Xeon processor MP, Family 0FH, Model 06H);2nd-level cache: 4 MByte, 16-way set associative, 64 byte line size\n");
	strcat(output[0x4A],"3rd-level cache: 6MByte, 12-way set associative, 64 byte line size\n");
	strcat(output[0x4B],"3rd-level cache: 8MByte, 16-way set associative, 64 byte line size\n");
	strcat(output[0x4C],"3rd-level cache: 12MByte, 12-way set associative, 64 byte line size\n");
	strcat(output[0x4D],"3rd-level cache: 16MByte, 16-way set associative, 64 byte line size\n");
	strcat(output[0x4E],"2nd-level cache: 6MByte, 24-way set associative, 64 byte line size\n");
	strcat(output[0x4F],"Instruction TLB: 4 KByte pages, 32 entries\n");
	strcat(output[0x50],"Instruction TLB: 4 KByte and 2-MByte or 4-MByte pages, 64 entries\n");
	strcat(output[0x51],"Instruction TLB: 4 KByte and 2-MByte or 4-MByte pages, 128 entries\n");
	strcat(output[0x52],"Instruction TLB: 4 KByte and 2-MByte or 4-MByte pages, 256 entries\n");
	strcat(output[0x55],"Instruction TLB: 2-MByte or 4-MByte pages, fully associative, 7 entries\n");
	strcat(output[0x56],"Data TLB0: 4 MByte pages, 4-way set associative, 16 entries\n");
	strcat(output[0x57],"Data TLB0: 4 KByte pages, 4-way associative, 16 entries\n");
	strcat(output[0x59],"Data TLB0: 4 KByte pages, fully associative, 16 entries\n");
	strcat(output[0x5A],"Data TLB0: 2 MByte or 4 MByte pages, 4-way set associative, 32 entries\n");
	strcat(output[0x5B],"Data TLB: 4 KByte and 4 MByte pages, 64 entries\n");
	strcat(output[0x5C],"Data TLB: 4 KByte and 4 MByte pages,128 entries\n");
	strcat(output[0x5D],"Data TLB: 4 KByte and 4 MByte pages,256 entries\n");
	strcat(output[0x60],"1st-level data cache: 16 KByte, 8-way set associative, 64 byte line size\n");
	strcat(output[0x61],"Instruction TLB: 4 KByte pages, fully associative, 48 entries\n");
	strcat(output[0x63],"Data TLB: 2 MByte or 4 MByte pages, 4-way set associative, 32 entries and a separate array with 1 GByte pages, 4-way set associative, 4 entries\n");
	strcat(output[0x64],"Data TLB: 4 KByte pages, 4-way set associative, 512 entries\n");
	strcat(output[0x66],"1st-level data cache: 8 KByte, 4-way set associative, 64 byte line size\n");
	strcat(output[0x67],"1st-level data cache: 16 KByte, 4-way set associative, 64 byte line size\n");
	strcat(output[0x68],"1st-level data cache: 32 KByte, 4-way set associative, 64 byte line size\n");
	strcat(output[0x6A],"uTLB: 4 KByte pages, 8-way set associative, 64 entries\n");
	strcat(output[0x6B],"DTLB: 4 KByte pages, 8-way set associative, 256 entries\n");
	strcat(output[0x6C],"DTLB: 2M/4M pages, 8-way set associative, 128 entries\n");
	strcat(output[0x6D],"DTLB: 1 GByte pages, fully associative, 16 entries\n");
	strcat(output[0x70],"Trace cache: 12 K-ìop, 8-way set associative\n");
	strcat(output[0x71],"Trace cache: 16 K-ìop, 8-way set associative\n");
	strcat(output[0x72],"Trace cache: 32 K-ìop, 8-way set associative\n");
	strcat(output[0x76],"Instruction TLB: 2M/4M pages, fully associative, 8 entries\n");
	strcat(output[0x78],"2nd-level cache: 1 MByte, 4-way set associative, 64byte line size\n");
	strcat(output[0x79],"2nd-level cache: 128 KByte, 8-way set associative, 64 byte line size, 2 lines per sector\n");
	strcat(output[0x7A],"2nd-level cache: 256 KByte, 8-way set associative, 64 byte line size, 2 lines per sector\n");
	strcat(output[0x7B],"2nd-level cache: 512 KByte, 8-way set associative, 64 byte line size, 2 lines per sector\n");
	strcat(output[0x7C],"2nd-level cache: 1 MByte, 8-way set associative, 64 byte line size, 2 lines per sector\n");
	strcat(output[0x7D],"2nd-level cache: 2 MByte, 8-way set associative, 64byte line size\n");
	strcat(output[0x7F],"2nd-level cache: 512 KByte, 2-way set associative, 64-byte line size\n");
	strcat(output[0x80],"2nd-level cache: 512 KByte, 8-way set associative, 64-byte line size\n");
	strcat(output[0x82],"2nd-level cache: 256 KByte, 8-way set associative, 32 byte line size\n");
	strcat(output[0x83],"2nd-level cache: 512 KByte, 8-way set associative, 32 byte line size\n");
	strcat(output[0x84],"2nd-level cache: 1 MByte, 8-way set associative, 32 byte line size\n");
	strcat(output[0x85],"2nd-level cache: 2 MByte, 8-way set associative, 32 byte line size\n");
	strcat(output[0x86],"2nd-level cache: 512 KByte, 4-way set associative, 64 byte line size\n");
	strcat(output[0x87],"2nd-level cache: 1 MByte, 8-way set associative, 64 byte line size\n");
	strcat(output[0xA0],"DTLB: 4k pages, fully associative, 32 entries\n");
	strcat(output[0xB0],"Instruction TLB: 4 KByte pages, 4-way set associative, 128 entries\n");
	strcat(output[0xB1],"Instruction TLB: 2M pages, 4-way, 8 entries or 4M pages, 4-way, 4 entries\n");
	strcat(output[0xB2],"Instruction TLB: 4KByte pages, 4-way set associative, 64 entries\n");
	strcat(output[0xB3],"Data TLB: 4 KByte pages, 4-way set associative, 128 entries\n");
	strcat(output[0xB4],"Data TLB1: 4 KByte pages, 4-way associative, 256 entries\n");
	strcat(output[0xB5],"Instruction TLB: 4KByte pages, 8-way set associative, 64 entries\n");
	strcat(output[0xB6],"Instruction TLB: 4KByte pages, 8-way set associative, 128 entries\n");
	strcat(output[0xBA],"Data TLB1: 4 KByte pages, 4-way associative, 64 entries\n");
	strcat(output[0xC0],"Data TLB: 4 KByte and 4 MByte pages, 4-way associative, 8 entries\n");
	strcat(output[0xC1],"Shared 2nd-Level TLB: 4 KByte/2MByte pages, 8-way associative, 1024 entries\n");
	strcat(output[0xC2],"DTLB: 4 KByte/2 MByte pages, 4-way associative, 16 entries\n");
	strcat(output[0xC3],"Shared 2nd-Level TLB: 4 KByte /2 MByte pages, 6-way associative, 1536 entries. Also 1GBbyte pages, 4-way, 16 entries.\n");
	strcat(output[0xC4],"DTLB: 2M/4M Byte pages, 4-way associative, 32 entries\n");
	strcat(output[0xCA],"Shared 2nd-Level TLB: 4 KByte pages, 4-way associative, 512 entries\n");
	strcat(output[0xD0],"3rd-level cache: 512 KByte, 4-way set associative, 64 byte line size\n");
	strcat(output[0xD1],"3rd-level cache: 1 MByte, 4-way set associative, 64 byte line size\n");
	strcat(output[0xD2],"3rd-level cache: 2 MByte, 4-way set associative, 64 byte line size\n");
	strcat(output[0xD6],"3rd-level cache: 1 MByte, 8-way set associative, 64 byte line size\n");
	strcat(output[0xD7],"3rd-level cache: 2 MByte, 8-way set associative, 64 byte line size\n");
	strcat(output[0xD8],"3rd-level cache: 4 MByte, 8-way set associative, 64 byte line size\n");
	strcat(output[0xDC],"3rd-level cache: 1.5 MByte, 12-way set associative, 64 byte line size\n");
	strcat(output[0xDD],"3rd-level cache: 3 MByte, 12-way set associative, 64 byte line size\n");
	strcat(output[0xDE],"3rd-level cache: 6 MByte, 12-way set associative, 64 byte line size\n");
	strcat(output[0xE2],"3rd-level cache: 2 MByte, 16-way set associative, 64 byte line size\n");
	strcat(output[0xE3],"3rd-level cache: 4 MByte, 16-way set associative, 64 byte line size\n");
	strcat(output[0xE4],"3rd-level cache: 8 MByte, 16-way set associative, 64 byte line size\n");
	strcat(output[0xEA],"3rd-level cache: 12MByte, 24-way set associative, 64 byte line size\n");
	strcat(output[0xEB],"3rd-level cache: 18MByte, 24-way set associative, 64 byte line size\n");
	strcat(output[0xEC],"3rd-level cache: 24MByte, 24-way set associative, 64 byte line size\n");
	strcat(output[0xF0],"64-Byte prefetching\n");
	strcat(output[0xF1],"128-Byte prefetching\n");
	strcat(output[0xFF],"CPUID leaf 2 does not report cache descriptor information, use CPUID leaf 4 to query cache parameters\n");
	strcat(output[0xFF],"CPUID leaf 2 does not report cache descriptor information, use CPUID leaf 4 to query cache parameters\\n");
}


int cmpfunc(const void *a, const void *b)
{
	return *(uint8_t *)a > *(uint8_t *) b;
}



int main(void)
{
	prepare();
	uint8_t byte[16];
	__asm__(
	"	movl	$0x02,%%eax\n"
	"	cpuid\n"
	"	movl	%%eax,%0\n"
	"	movl	%%ebx,%1\n"
	"	movl	%%ecx,%2\n"
	"	movl	%%edx,%3\n"
	:	"=m" (byte[0]), "=m" (byte[4]),"=m" (byte[8]), "=m" (byte[12])
	);
	qsort(byte,16,sizeof(uint8_t),cmpfunc);
	if(byte[0]!=0) printf("%s",output[byte[0]]);
	for(int i=1;i<16;i++){
		if(byte[i]!=byte[i-1] && byte[i]!=0) printf("%s",output[byte[i]]);
	}
	return 0;
}