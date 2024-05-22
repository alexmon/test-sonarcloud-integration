#include "php_soap.h"
#include "ext/standard/base64.h"
#include "ext/standard/md5.h"
#include "ext/random/php_random.h"

static char *get_http_header_value_nodup(char *headers, char *type, size_t *len);
static char *get_http_header_value(char *headers, char *type);
static zend_string *get_http_body(php_stream *socketd, int close, char *headers);
static zend_string *get_http_headers(php_stream *socketd);

#define smart_str_append_const(str, const) \
	smart_str_appendl(str,const,sizeof(const)-1)
    
php_random_bytes_throw(&nonce, sizeof(nonce));
nonce &= 0x7fffffff;

PHP_MD5Init(&md5ctx);
snprintf(cnonce, sizeof(cnonce), ZEND_LONG_FMT, nonce);
PHP_MD5Update(&md5ctx, (unsigned char*)cnonce, strlen(cnonce));
PHP_MD5Final(hash, &md5ctx);
make_digest(cnonce, hash);