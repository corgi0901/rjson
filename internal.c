#include <malloc.h>
#include <string.h>

#include "internal.h"

char *copy_str(char *str)
{
	char *copy = (char *)calloc(strlen(str) + 1, sizeof(char));
	strcpy(copy, str);
	return copy;
}

rjson_t *rjson_string(char *str)
{
	rjson_t *obj = (rjson_t *)calloc(1, sizeof(rjson_t));
	obj->type = RJSON_STRING;
	obj->content.str = copy_str(str);
	return obj;
}

rjson_t *rjson_real(double real)
{
	rjson_t *obj = (rjson_t *)calloc(1, sizeof(rjson_t));
	obj->type = RJSON_REAL;
	obj->content.real = real;
	return obj;
}

rjson_t *rjson_number(long number)
{
	rjson_t *obj = (rjson_t *)calloc(1, sizeof(rjson_t));
	obj->type = RJSON_NUMBER;
	obj->content.number = number;
	return obj;
}

rjson_t *rjson_true(void)
{
	rjson_t *obj = (rjson_t *)calloc(1, sizeof(rjson_t));
	obj->type = RJSON_TRUE;
	return obj;
}

rjson_t *rjson_false(void)
{
	rjson_t *obj = (rjson_t *)calloc(1, sizeof(rjson_t));
	obj->type = RJSON_FALSE;
	return obj;
}

rjson_t *rjson_null(void)
{
	rjson_t *obj = (rjson_t *)calloc(1, sizeof(rjson_t));
	obj->type = RJSON_NULL;
	return obj;
}