#ifndef _RJSON_H_
#define _RJSON_H_

typedef enum
{
	RJSON_OBJECT,
	RJSON_ARRAY,
	RJSON_NUMBER,
	RJSON_REAL,
	RJSON_STRING,
	RJSON_TRUE,
	RJSON_FALSE,
	RJSON_NULL,
} RJSON_TYPE;

typedef enum
{
	RJSON_OK = 0,
	RJSON_MEMORY_ALLOC_FAILED,
} RJSON_ERR;

typedef struct object_t
{
	char *key;
	struct rjson_t *value;
	struct object_t *next;
} object_t;

typedef struct array_t
{
	struct rjson_t *value;
	struct array_t *next;
} array_t;

typedef struct rjson_t
{
	RJSON_TYPE type;

	union content
	{
		/* object */
		struct object_t *object;

		/* array */
		struct array_t *array;

		/* number */
		long number;

		/* real */
		double real;

		/* string */
		char *str;
	} content;

} rjson_t;

/* JSON Object */
rjson_t *rjson_object_create(void);

rjson_t *rjson_object_create_with_string(char *key, char *value);
rjson_t *rjson_object_create_with_number(char *key, long value);
rjson_t *rjson_object_create_with_real(char *key, double real);
rjson_t *rjson_object_create_with_value(char *key, rjson_t *value);
rjson_t *rjson_object_create_with_true(char *key);
rjson_t *rjson_object_create_with_false(char *key);
rjson_t *rjson_object_create_with_null(char *key);

rjson_t *rjson_object_add_string(rjson_t *json, char *key, char *value);
rjson_t *rjson_object_add_number(rjson_t *json, char *key, long value);
rjson_t *rjson_object_add_real(rjson_t *json, char *key, double real);
rjson_t *rjson_object_add_value(rjson_t *json, char *key, rjson_t *value);
rjson_t *rjson_object_add_true(rjson_t *json, char *key);
rjson_t *rjson_object_add_false(rjson_t *json, char *key);
rjson_t *rjson_object_add_null(rjson_t *json, char *key);

rjson_t *rjson_object_get_value(rjson_t *json, char *key);

/* JSON Array */
rjson_t *rjson_array_create(void);

rjson_t *rjson_array_create_with_string(char *value);
rjson_t *rjson_array_create_with_number(long value);
rjson_t *rjson_array_create_with_real(double real);
rjson_t *rjson_array_create_with_value(rjson_t *value);
rjson_t *rjson_array_create_with_true();
rjson_t *rjson_array_create_with_false();
rjson_t *rjson_array_create_with_null();

rjson_t *rjson_array_add_string(rjson_t *json, char *value);
rjson_t *rjson_array_add_number(rjson_t *json, long value);
rjson_t *rjson_array_add_real(rjson_t *json, double real);
rjson_t *rjson_array_add_value(rjson_t *json, rjson_t *value);
rjson_t *rjson_array_add_true(rjson_t *json);
rjson_t *rjson_array_add_false(rjson_t *json);
rjson_t *rjson_array_add_null(rjson_t *json);

rjson_t *rjson_array_get_value(rjson_t *json, int index);

/* Utilily */
RJSON_TYPE rjson_get_type(rjson_t *json);

/* Common */
void rjson_free(rjson_t **json);

/* Debug */
void rjson_print(rjson_t *json);

#endif /* _RJSON_H_ */
