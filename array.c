#include <malloc.h>
#include <string.h>

#include "rjson.h"
#include "internal.h"

rjson_t *rjson_array_create(void)
{
	rjson_t *obj = (rjson_t *)calloc(1, sizeof(rjson_t));

	if (obj == NULL)
	{
		return NULL;
	}

	/* create null object */
	obj->type = RJSON_ARRAY;
	obj->content.array = NULL;

	return obj;
}

rjson_t *rjson_array_create_with_string(char *value)
{
	rjson_t *obj = rjson_array_create();

	if (obj)
	{
		obj->type = RJSON_ARRAY;
		obj->content.array = (array_t *)calloc(1, sizeof(array_t));
		obj->content.array->value = rjson_string(value);
	}

	return obj;
}

rjson_t *rjson_array_create_with_number(long value)
{
	rjson_t *obj = rjson_array_create();

	if (obj)
	{
		obj->type = RJSON_ARRAY;
		obj->content.array = (array_t *)calloc(1, sizeof(array_t));
		obj->content.array->value = rjson_number(value);
	}

	return obj;
}

rjson_t *rjson_array_create_with_real(double real)
{
	rjson_t *obj = rjson_array_create();

	if (obj)
	{
		obj->type = RJSON_ARRAY;
		obj->content.array = (array_t *)calloc(1, sizeof(array_t));
		obj->content.array->value = rjson_real(real);
	}

	return obj;
}

rjson_t *rjson_array_create_with_value(rjson_t *value)
{
	rjson_t *obj = rjson_array_create();

	if (obj)
	{
		obj->type = RJSON_ARRAY;
		obj->content.array = (array_t *)calloc(1, sizeof(array_t));
		obj->content.array->value = value;
	}

	return obj;
}

rjson_t *rjson_array_create_with_true()
{
	rjson_t *obj = rjson_array_create();

	if (obj)
	{
		obj->type = RJSON_ARRAY;
		obj->content.array = (array_t *)calloc(1, sizeof(array_t));
		obj->content.array->value = rjson_true();
	}

	return obj;
}

rjson_t *rjson_array_create_with_false()
{
	rjson_t *obj = rjson_array_create();

	if (obj)
	{
		obj->type = RJSON_ARRAY;
		obj->content.array = (array_t *)calloc(1, sizeof(array_t));
		obj->content.array->value = rjson_false();
	}

	return obj;
}

rjson_t *rjson_array_create_with_null()
{
	rjson_t *obj = rjson_array_create();

	if (obj)
	{
		obj->type = RJSON_ARRAY;
		obj->content.array = (array_t *)calloc(1, sizeof(array_t));
		obj->content.array->value = rjson_null();
	}

	return obj;
}

rjson_t *rjson_array_add_string(rjson_t *json, char *value)
{
	if (json == NULL)
	{
		return NULL;
	}

	if (json->type == RJSON_ARRAY)
	{
		if (json->content.array == NULL)
		{
			json->content.array = (array_t *)calloc(1, sizeof(array_t));
			json->content.array->value = rjson_string(value);
		}
		else
		{
			array_t *tail = json->content.array;
			while (tail->next != NULL)
			{
				tail = tail->next;
			}
			tail->next = (array_t *)calloc(1, sizeof(array_t));
			tail->next->value = rjson_string(value);
		}
		return json;
	}

	return json;
}

rjson_t *rjson_array_add_number(rjson_t *json, long value)
{
	if (json == NULL)
	{
		return NULL;
	}

	if (json->type == RJSON_ARRAY)
	{
		if (json->content.array == NULL)
		{
			json->content.array = (array_t *)calloc(1, sizeof(array_t));
			json->content.array->value = rjson_number(value);
		}
		else
		{
			array_t *tail = json->content.array;
			while (tail->next != NULL)
			{
				tail = tail->next;
			}
			tail->next = (array_t *)calloc(1, sizeof(array_t));
			tail->next->value = rjson_number(value);
		}
		return json;
	}

	return json;
}

rjson_t *rjson_array_add_real(rjson_t *json, double real)
{
	if (json == NULL)
	{
		return NULL;
	}

	if (json->type == RJSON_ARRAY)
	{
		if (json->content.array == NULL)
		{
			json->content.array = (array_t *)calloc(1, sizeof(array_t));
			json->content.array->value = rjson_real(real);
		}
		else
		{
			array_t *tail = json->content.array;
			while (tail->next != NULL)
			{
				tail = tail->next;
			}
			tail->next = (array_t *)calloc(1, sizeof(array_t));
			tail->next->value = rjson_real(real);
		}
		return json;
	}

	return json;
}

rjson_t *rjson_array_add_value(rjson_t *json, rjson_t *value)
{
	if (json == NULL)
	{
		return NULL;
	}

	if (json->type == RJSON_ARRAY)
	{
		if (json->content.array == NULL)
		{
			json->content.array = (array_t *)calloc(1, sizeof(array_t));
			json->content.array->value = value;
		}
		else
		{
			array_t *tail = json->content.array;
			while (tail->next != NULL)
			{
				tail = tail->next;
			}
			tail->next = (array_t *)calloc(1, sizeof(array_t));
			tail->next->value = value;
		}
		return json;
	}

	return json;
}

rjson_t *rjson_array_add_true(rjson_t *json)
{
	if (json == NULL)
	{
		return NULL;
	}

	if (json->type == RJSON_ARRAY)
	{
		if (json->content.array == NULL)
		{
			json->content.array = (array_t *)calloc(1, sizeof(array_t));
			json->content.array->value = rjson_true();
		}
		else
		{
			array_t *tail = json->content.array;
			while (tail->next != NULL)
			{
				tail = tail->next;
			}
			tail->next = (array_t *)calloc(1, sizeof(array_t));
			tail->next->value = rjson_true();
		}
		return json;
	}

	return json;
}

rjson_t *rjson_array_add_false(rjson_t *json)
{
	if (json == NULL)
	{
		return NULL;
	}

	if (json->type == RJSON_ARRAY)
	{
		if (json->content.array == NULL)
		{
			json->content.array = (array_t *)calloc(1, sizeof(array_t));
			json->content.array->value = rjson_false();
		}
		else
		{
			array_t *tail = json->content.array;
			while (tail->next != NULL)
			{
				tail = tail->next;
			}
			tail->next = (array_t *)calloc(1, sizeof(array_t));
			tail->next->value = rjson_false();
		}
		return json;
	}

	return json;
}

rjson_t *rjson_array_add_null(rjson_t *json)
{
	if (json == NULL)
	{
		return NULL;
	}

	if (json->type == RJSON_ARRAY)
	{
		if (json->content.array == NULL)
		{
			json->content.array = (array_t *)calloc(1, sizeof(array_t));
			json->content.array->value = rjson_null();
		}
		else
		{
			array_t *tail = json->content.array;
			while (tail->next != NULL)
			{
				tail = tail->next;
			}
			tail->next = (array_t *)calloc(1, sizeof(array_t));
			tail->next->value = rjson_null();
		}
		return json;
	}

	return json;
}

rjson_t *rjson_array_get_value(rjson_t *json, int index)
{
	if (json == NULL)
	{
		return NULL;
	}

	if (json->type != RJSON_ARRAY)
	{
		return NULL;
	}

	array_t *elem = json->content.array;
	for (int i = 0; i < index; i++)
	{
		elem = elem->next;
	}

	return elem->value;
}
