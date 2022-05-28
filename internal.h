#ifndef _RJSON_INTERNAL_
#define _RJSON_INTERNAL_

#include "rjson.h"

char *copy_str(char *str);
rjson_t *rjson_string(char *str);
rjson_t *rjson_number(long number);
rjson_t *rjson_real(double real);
rjson_t *rjson_true(void);
rjson_t *rjson_false(void);
rjson_t *rjson_null(void);

#endif /* _RJSON_INTERNAL_ */