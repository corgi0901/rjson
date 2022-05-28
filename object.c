#include <malloc.h>
#include <string.h>

#include "rjson.h"
#include "internal.h"

rjson_t *rjson_object_create(void)
{
	rjson_t *obj = (rjson_t *)calloc(1, sizeof(rjson_t));

	if (obj == NULL)
	{
		return NULL;
	}

	/* create null object */
	obj->type = RJSON_OBJECT;
	obj->content.object = NULL;

	return obj;
}

rjson_t *rjson_object_create_with_string(char *key, char *value)
{
	rjson_t *obj = rjson_object_create();

	if (obj)
	{
		obj->type = RJSON_OBJECT;
		obj->content.object = (object_t *)calloc(1, sizeof(object_t));
		if (obj->content.object)
		{
			obj->content.object->key = copy_str(key);
			obj->content.object->value = rjson_string(value);
		}
	}

	return obj;
}

rjson_t *rjson_object_create_with_number(char *key, long value)
{
	rjson_t *obj = rjson_object_create();

	if (obj)
	{
		obj->type = RJSON_OBJECT;
		obj->content.object = (object_t *)calloc(1, sizeof(object_t));
		if (obj->content.object)
		{
			obj->content.object->key = copy_str(key);
			obj->content.object->value = rjson_number(value);
		}
	}

	return obj;
}

rjson_t *rjson_object_create_with_real(char *key, double real)
{
	rjson_t *obj = rjson_object_create();

	if (obj)
	{
		obj->type = RJSON_OBJECT;
		obj->content.object = (object_t *)calloc(1, sizeof(object_t));
		if (obj->content.object)
		{
			obj->content.object->key = copy_str(key);
			obj->content.object->value = rjson_real(real);
		}
	}

	return obj;
}

rjson_t *rjson_object_create_with_value(char *key, rjson_t *value)
{
	rjson_t *obj = rjson_object_create();

	if (obj)
	{
		obj->type = RJSON_OBJECT;
		obj->content.object = (object_t *)calloc(1, sizeof(object_t));
		if (obj->content.object)
		{
			obj->content.object->key = copy_str(key);
			obj->content.object->value = value;
		}
	}

	return obj;
}

rjson_t *rjson_object_create_with_true(char *key)
{
	rjson_t *obj = rjson_object_create();

	if (obj)
	{
		obj->type = RJSON_OBJECT;
		obj->content.object = (object_t *)calloc(1, sizeof(object_t));
		if (obj->content.object)
		{
			obj->content.object->key = copy_str(key);
			obj->content.object->value = rjson_true();
		}
	}

	return obj;
}

rjson_t *rjson_object_create_with_false(char *key)
{
	rjson_t *obj = rjson_object_create();

	if (obj)
	{
		obj->type = RJSON_OBJECT;
		obj->content.object = (object_t *)calloc(1, sizeof(object_t));
		if (obj->content.object)
		{
			obj->content.object->key = copy_str(key);
			obj->content.object->value = rjson_false();
		}
	}

	return obj;
}

rjson_t *rjson_object_create_with_null(char *key)
{
	rjson_t *obj = rjson_object_create();

	if (obj)
	{
		obj->type = RJSON_OBJECT;
		obj->content.object = (object_t *)calloc(1, sizeof(object_t));
		if (obj->content.object)
		{
			obj->content.object->key = copy_str(key);
			obj->content.object->value = rjson_null();
		}
	}

	return obj;
}

rjson_t *rjson_object_add_string(rjson_t *json, char *key, char *value)
{
	if (json == NULL)
	{
		return NULL;
	}

	if (json->type == RJSON_OBJECT)
	{
		if (json->content.object == NULL)
		{
			json->content.object = (object_t *)calloc(1, sizeof(object_t));
			json->content.object->key = copy_str(key);
			json->content.object->value = rjson_string(value);
		}
		else
		{
			object_t *tail = json->content.object;
			while (tail->next != NULL)
			{
				tail = tail->next;
			}
			tail->next = (object_t *)calloc(1, sizeof(object_t));
			tail->next->key = copy_str(key);
			tail->next->value = rjson_string(value);
		}
		return json;
	}

	return json;
}

rjson_t *rjson_object_add_number(rjson_t *json, char *key, long value)
{
	if (json == NULL)
	{
		return NULL;
	}

	if (json->type == RJSON_OBJECT)
	{
		if (json->content.object == NULL)
		{
			json->content.object = (object_t *)calloc(1, sizeof(object_t));
			json->content.object->key = copy_str(key);
			json->content.object->value = rjson_number(value);
		}
		else
		{
			object_t *tail = json->content.object;
			while (tail->next != NULL)
			{
				tail = tail->next;
			}
			tail->next = (object_t *)calloc(1, sizeof(object_t));
			tail->next->key = copy_str(key);
			tail->next->value = rjson_number(value);
		}
		return json;
	}

	return json;
}

rjson_t *rjson_object_add_real(rjson_t *json, char *key, double real)
{
	if (json == NULL)
	{
		return NULL;
	}

	if (json->type == RJSON_OBJECT)
	{
		if (json->content.object == NULL)
		{
			json->content.object = (object_t *)calloc(1, sizeof(object_t));
			json->content.object->key = copy_str(key);
			json->content.object->value = rjson_real(real);
		}
		else
		{
			object_t *tail = json->content.object;
			while (tail->next != NULL)
			{
				tail = tail->next;
			}
			tail->next = (object_t *)calloc(1, sizeof(object_t));
			tail->next->key = copy_str(key);
			tail->next->value = rjson_real(real);
		}
		return json;
	}

	return json;
}

rjson_t *rjson_object_add_value(rjson_t *json, char *key, rjson_t *value)
{
	if (json == NULL)
	{
		return NULL;
	}

	if (json->type == RJSON_OBJECT)
	{
		if (json->content.object == NULL)
		{
			json->content.object = (object_t *)calloc(1, sizeof(object_t));
			json->content.object->key = copy_str(key);
			json->content.object->value = value;
		}
		else
		{
			object_t *tail = json->content.object;
			while (tail->next != NULL)
			{
				tail = tail->next;
			}
			tail->next = (object_t *)calloc(1, sizeof(object_t));
			tail->next->key = copy_str(key);
			tail->next->value = value;
		}
		return json;
	}

	return json;
}

rjson_t *rjson_object_add_true(rjson_t *json, char *key)
{
	if (json == NULL)
	{
		return NULL;
	}

	if (json->type == RJSON_OBJECT)
	{
		if (json->content.object == NULL)
		{
			json->content.object = (object_t *)calloc(1, sizeof(object_t));
			json->content.object->key = copy_str(key);
			json->content.object->value = rjson_true();
		}
		else
		{
			object_t *tail = json->content.object;
			while (tail->next != NULL)
			{
				tail = tail->next;
			}
			tail->next = (object_t *)calloc(1, sizeof(object_t));
			tail->next->key = copy_str(key);
			tail->next->value = rjson_true();
		}
		return json;
	}

	return json;
}

rjson_t *rjson_object_add_false(rjson_t *json, char *key)
{
	if (json == NULL)
	{
		return NULL;
	}

	if (json->type == RJSON_OBJECT)
	{
		if (json->content.object == NULL)
		{
			json->content.object = (object_t *)calloc(1, sizeof(object_t));
			json->content.object->key = copy_str(key);
			json->content.object->value = rjson_false();
		}
		else
		{
			object_t *tail = json->content.object;
			while (tail->next != NULL)
			{
				tail = tail->next;
			}
			tail->next = (object_t *)calloc(1, sizeof(object_t));
			tail->next->key = copy_str(key);
			tail->next->value = rjson_false();
		}
		return json;
	}

	return json;
}

rjson_t *rjson_object_add_null(rjson_t *json, char *key)
{
	if (json == NULL)
	{
		return NULL;
	}

	if (json->type == RJSON_OBJECT)
	{
		if (json->content.object == NULL)
		{
			json->content.object = (object_t *)calloc(1, sizeof(object_t));
			json->content.object->key = copy_str(key);
			json->content.object->value = rjson_null();
		}
		else
		{
			object_t *tail = json->content.object;
			while (tail->next != NULL)
			{
				tail = tail->next;
			}
			tail->next = (object_t *)calloc(1, sizeof(object_t));
			tail->next->key = copy_str(key);
			tail->next->value = rjson_null();
		}
		return json;
	}

	return json;
}

rjson_t *rjson_object_get_value(rjson_t *json, char *key)
{
	if (json->type != RJSON_OBJECT)
	{
		return NULL;
	}

	object_t *node = json->content.object;
	while (node)
	{
		if (node->key != NULL && strcmp(node->key, key) == 0)
		{
			return node->value;
		}
		node = node->next;
	}

	return NULL;
}