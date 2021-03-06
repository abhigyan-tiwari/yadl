#include<stdio.h>
#include<string.h>  
#include<stdlib.h> 
#include<unistd.h>
#include<dirent.h>
#include<errno.h>
#include<ctype.h> 
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<time.h> 
#include <libgen.h> 
#include<openssl/md5.h>
#if defined(CFLAG)
#define COMMON_DIGEST_FOR_OPENSSL
#include <CommonCrypto/CommonDigest.h>
#include <linux/limits.h>
#define SHA1 CC_SHA1
#else
#include<openssl/ssl.h>
#include<openssl/sha.h>
#endif
#define NAME_SIZE 100
#define INT_SIZE sizeof(int)

struct block_store
{
        size_t fd_block;
};


/*@description:Function to create blockstore
@in: void
@out: int 
@return: -1 for error and 0 if created successfully */
int init_block_store(char* path);

/*@description:Function to get specific block from specified position 
@in: int pos-position of block,
@out: char*
@return: block */
char* get_block(int pos, int *l);

/*@description:Function to close filedescriptor of blockstore
@in: void
@out: int 
@return: -1 for error and 0 if closed successfully */
int fini_block_store();
