#include "pq_config.h"
#include <stdint.h>
#include "j2s.h"

#define J2S_MAGIC 624677654
#define J2S_NUM_OBJ 38
#define J2S_NUM_STRUCT 6
#define J2S_NUM_ENUM 0
#define J2S_NUM_ENUM_VALUE 0

static void _j2s_init(j2s_ctx *ctx) {
	j2s_obj *obj;

	static j2s_obj objs[J2S_NUM_OBJ];
	static j2s_struct structs[J2S_NUM_STRUCT];
	static j2s_enum enums[J2S_NUM_ENUM];
	static j2s_enum_value enum_values[J2S_NUM_ENUM_VALUE];

	ctx->magic = J2S_MAGIC;
	ctx->priv = NULL;
	ctx->objs = (j2s_obj *)&objs;
	ctx->structs = (j2s_struct *)&structs;
	ctx->enums = (j2s_enum *)&enums;
	ctx->enum_values = (j2s_enum_value *)&enum_values;

	ctx->num_obj = J2S_NUM_OBJ;
	ctx->num_struct = J2S_NUM_STRUCT;
	ctx->num_enum = J2S_NUM_ENUM;
	ctx->num_enum_value = J2S_NUM_ENUM_VALUE;


#ifndef J2S_ENABLE_DESC
	ctx->num_desc = 0;
#else
	static const char *descs[J2S_NUM_OBJ];
	ctx->descs = (const char **)descs;
	ctx->num_desc = J2S_NUM_OBJ;
#endif

	ctx->root_index = 5;

	obj = &ctx->objs[0];
	strcpy(obj->name, "cscEnable");
	obj->type = J2S_TYPE_INT_8;
	obj->flags = 0 ;
	obj->offset = (uintptr_t)&((csc*)0)->cscEnable;
	obj->elem_size = sizeof(((csc*)0)->cscEnable);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = 1;
	obj->len_index = -1;
	obj->next_index = 1;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[1];
	strcpy(obj->name, "cscMode");
	obj->type = J2S_TYPE_STRING;
	obj->flags = 0 | J2S_FLAG_POINTER;
	obj->offset = (uintptr_t)&((csc*)0)->cscMode;
	obj->elem_size = sizeof(((csc*)0)->cscMode[0]);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = 1;
	obj->len_index = -1;
	obj->next_index = 2;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[2];
	strcpy(obj->name, "cscBrightness");
	obj->type = J2S_TYPE_UINT_32;
	obj->flags = 0 ;
	obj->offset = (uintptr_t)&((csc*)0)->cscBrightness;
	obj->elem_size = sizeof(((csc*)0)->cscBrightness);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = 1;
	obj->len_index = -1;
	obj->next_index = 3;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[3];
	strcpy(obj->name, "cscHue");
	obj->type = J2S_TYPE_UINT_32;
	obj->flags = 0 ;
	obj->offset = (uintptr_t)&((csc*)0)->cscHue;
	obj->elem_size = sizeof(((csc*)0)->cscHue);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = 1;
	obj->len_index = -1;
	obj->next_index = 4;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[4];
	strcpy(obj->name, "cscContrast");
	obj->type = J2S_TYPE_UINT_32;
	obj->flags = 0 ;
	obj->offset = (uintptr_t)&((csc*)0)->cscContrast;
	obj->elem_size = sizeof(((csc*)0)->cscContrast);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = 1;
	obj->len_index = -1;
	obj->next_index = 5;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[5];
	strcpy(obj->name, "cscSaturation");
	obj->type = J2S_TYPE_UINT_32;
	obj->flags = 0 ;
	obj->offset = (uintptr_t)&((csc*)0)->cscSaturation;
	obj->elem_size = sizeof(((csc*)0)->cscSaturation);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = 1;
	obj->len_index = -1;
	obj->next_index = 6;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[6];
	strcpy(obj->name, "cscRGain");
	obj->type = J2S_TYPE_UINT_32;
	obj->flags = 0 ;
	obj->offset = (uintptr_t)&((csc*)0)->cscRGain;
	obj->elem_size = sizeof(((csc*)0)->cscRGain);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = 1;
	obj->len_index = -1;
	obj->next_index = 7;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[7];
	strcpy(obj->name, "cscGGain");
	obj->type = J2S_TYPE_UINT_32;
	obj->flags = 0 ;
	obj->offset = (uintptr_t)&((csc*)0)->cscGGain;
	obj->elem_size = sizeof(((csc*)0)->cscGGain);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = 1;
	obj->len_index = -1;
	obj->next_index = 8;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[8];
	strcpy(obj->name, "cscBGain");
	obj->type = J2S_TYPE_UINT_32;
	obj->flags = 0 ;
	obj->offset = (uintptr_t)&((csc*)0)->cscBGain;
	obj->elem_size = sizeof(((csc*)0)->cscBGain);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = 1;
	obj->len_index = -1;
	obj->next_index = -1;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[9];
	strcpy(obj->name, "dciEnable");
	obj->type = J2S_TYPE_INT_8;
	obj->flags = 0 ;
	obj->offset = (uintptr_t)&((dci*)0)->dciEnable;
	obj->elem_size = sizeof(((dci*)0)->dciEnable);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = 1;
	obj->len_index = -1;
	obj->next_index = 10;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[10];
	strcpy(obj->name, "dciWgtCoef_low");
	obj->type = J2S_TYPE_UINT_16;
	obj->flags = 0 | J2S_FLAG_ARRAY;
	obj->offset = (uintptr_t)&((dci*)0)->dciWgtCoef_low;
	obj->elem_size = sizeof(((dci*)0)->dciWgtCoef_low[0]);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = (sizeof(((dci*)0)->dciWgtCoef_low) / obj->elem_size);
	obj->len_index = -1;
	obj->next_index = 11;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[11];
	strcpy(obj->name, "dciWgtCoef_mid");
	obj->type = J2S_TYPE_UINT_16;
	obj->flags = 0 | J2S_FLAG_ARRAY;
	obj->offset = (uintptr_t)&((dci*)0)->dciWgtCoef_mid;
	obj->elem_size = sizeof(((dci*)0)->dciWgtCoef_mid[0]);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = (sizeof(((dci*)0)->dciWgtCoef_mid) / obj->elem_size);
	obj->len_index = -1;
	obj->next_index = 12;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[12];
	strcpy(obj->name, "dciWgtCoef_high");
	obj->type = J2S_TYPE_UINT_16;
	obj->flags = 0 | J2S_FLAG_ARRAY;
	obj->offset = (uintptr_t)&((dci*)0)->dciWgtCoef_high;
	obj->elem_size = sizeof(((dci*)0)->dciWgtCoef_high[0]);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = (sizeof(((dci*)0)->dciWgtCoef_high) / obj->elem_size);
	obj->len_index = -1;
	obj->next_index = 13;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[13];
	strcpy(obj->name, "dciWeight_low");
	obj->type = J2S_TYPE_UINT_16;
	obj->flags = 0 | J2S_FLAG_ARRAY;
	obj->offset = (uintptr_t)&((dci*)0)->dciWeight_low;
	obj->elem_size = sizeof(((dci*)0)->dciWeight_low[0]);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = (sizeof(((dci*)0)->dciWeight_low) / obj->elem_size);
	obj->len_index = -1;
	obj->next_index = 14;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[14];
	strcpy(obj->name, "dciWeight_mid");
	obj->type = J2S_TYPE_UINT_16;
	obj->flags = 0 | J2S_FLAG_ARRAY;
	obj->offset = (uintptr_t)&((dci*)0)->dciWeight_mid;
	obj->elem_size = sizeof(((dci*)0)->dciWeight_mid[0]);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = (sizeof(((dci*)0)->dciWeight_mid) / obj->elem_size);
	obj->len_index = -1;
	obj->next_index = 15;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[15];
	strcpy(obj->name, "dciWeight_high");
	obj->type = J2S_TYPE_UINT_16;
	obj->flags = 0 | J2S_FLAG_ARRAY;
	obj->offset = (uintptr_t)&((dci*)0)->dciWeight_high;
	obj->elem_size = sizeof(((dci*)0)->dciWeight_high[0]);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = (sizeof(((dci*)0)->dciWeight_high) / obj->elem_size);
	obj->len_index = -1;
	obj->next_index = -1;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[16];
	strcpy(obj->name, "acmEnable");
	obj->type = J2S_TYPE_INT_8;
	obj->flags = 0 ;
	obj->offset = (uintptr_t)&((acm*)0)->acmEnable;
	obj->elem_size = sizeof(((acm*)0)->acmEnable);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = 1;
	obj->len_index = -1;
	obj->next_index = 17;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[17];
	strcpy(obj->name, "acmTableDeltaYbyH");
	obj->type = J2S_TYPE_UINT_8;
	obj->flags = 0 | J2S_FLAG_ARRAY;
	obj->offset = (uintptr_t)&((acm*)0)->acmTableDeltaYbyH;
	obj->elem_size = sizeof(((acm*)0)->acmTableDeltaYbyH[0]);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = (sizeof(((acm*)0)->acmTableDeltaYbyH) / obj->elem_size);
	obj->len_index = -1;
	obj->next_index = 18;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[18];
	strcpy(obj->name, "acmTableDeltaHbyH");
	obj->type = J2S_TYPE_UINT_8;
	obj->flags = 0 | J2S_FLAG_ARRAY;
	obj->offset = (uintptr_t)&((acm*)0)->acmTableDeltaHbyH;
	obj->elem_size = sizeof(((acm*)0)->acmTableDeltaHbyH[0]);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = (sizeof(((acm*)0)->acmTableDeltaHbyH) / obj->elem_size);
	obj->len_index = -1;
	obj->next_index = 19;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[19];
	strcpy(obj->name, "acmTableDeltaSbyH");
	obj->type = J2S_TYPE_UINT_8;
	obj->flags = 0 | J2S_FLAG_ARRAY;
	obj->offset = (uintptr_t)&((acm*)0)->acmTableDeltaSbyH;
	obj->elem_size = sizeof(((acm*)0)->acmTableDeltaSbyH[0]);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = (sizeof(((acm*)0)->acmTableDeltaSbyH) / obj->elem_size);
	obj->len_index = -1;
	obj->next_index = 20;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[20];
	strcpy(obj->name, "acmTableGainYbyY");
	obj->type = J2S_TYPE_UINT_8;
	obj->flags = 0 | J2S_FLAG_ARRAY;
	obj->offset = (uintptr_t)&((acm*)0)->acmTableGainYbyY;
	obj->elem_size = sizeof(((acm*)0)->acmTableGainYbyY[0]);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = (sizeof(((acm*)0)->acmTableGainYbyY) / obj->elem_size);
	obj->len_index = -1;
	obj->next_index = 21;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[21];
	strcpy(obj->name, "acmTableGainHbyY");
	obj->type = J2S_TYPE_UINT_8;
	obj->flags = 0 | J2S_FLAG_ARRAY;
	obj->offset = (uintptr_t)&((acm*)0)->acmTableGainHbyY;
	obj->elem_size = sizeof(((acm*)0)->acmTableGainHbyY[0]);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = (sizeof(((acm*)0)->acmTableGainHbyY) / obj->elem_size);
	obj->len_index = -1;
	obj->next_index = 22;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[22];
	strcpy(obj->name, "acmTableGainSbyY");
	obj->type = J2S_TYPE_UINT_8;
	obj->flags = 0 | J2S_FLAG_ARRAY;
	obj->offset = (uintptr_t)&((acm*)0)->acmTableGainSbyY;
	obj->elem_size = sizeof(((acm*)0)->acmTableGainSbyY[0]);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = (sizeof(((acm*)0)->acmTableGainSbyY) / obj->elem_size);
	obj->len_index = -1;
	obj->next_index = 23;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[23];
	strcpy(obj->name, "acmTableGainYbyS");
	obj->type = J2S_TYPE_UINT_8;
	obj->flags = 0 | J2S_FLAG_ARRAY;
	obj->offset = (uintptr_t)&((acm*)0)->acmTableGainYbyS;
	obj->elem_size = sizeof(((acm*)0)->acmTableGainYbyS[0]);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = (sizeof(((acm*)0)->acmTableGainYbyS) / obj->elem_size);
	obj->len_index = -1;
	obj->next_index = 24;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[24];
	strcpy(obj->name, "acmTableGainHbyS");
	obj->type = J2S_TYPE_UINT_8;
	obj->flags = 0 | J2S_FLAG_ARRAY;
	obj->offset = (uintptr_t)&((acm*)0)->acmTableGainHbyS;
	obj->elem_size = sizeof(((acm*)0)->acmTableGainHbyS[0]);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = (sizeof(((acm*)0)->acmTableGainHbyS) / obj->elem_size);
	obj->len_index = -1;
	obj->next_index = 25;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[25];
	strcpy(obj->name, "acmTableGainSbyS");
	obj->type = J2S_TYPE_UINT_8;
	obj->flags = 0 | J2S_FLAG_ARRAY;
	obj->offset = (uintptr_t)&((acm*)0)->acmTableGainSbyS;
	obj->elem_size = sizeof(((acm*)0)->acmTableGainSbyS[0]);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = (sizeof(((acm*)0)->acmTableGainSbyS) / obj->elem_size);
	obj->len_index = -1;
	obj->next_index = 26;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[26];
	strcpy(obj->name, "lumGain");
	obj->type = J2S_TYPE_UINT_32;
	obj->flags = 0 ;
	obj->offset = (uintptr_t)&((acm*)0)->lumGain;
	obj->elem_size = sizeof(((acm*)0)->lumGain);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = 1;
	obj->len_index = -1;
	obj->next_index = 27;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[27];
	strcpy(obj->name, "hueGain");
	obj->type = J2S_TYPE_UINT_32;
	obj->flags = 0 ;
	obj->offset = (uintptr_t)&((acm*)0)->hueGain;
	obj->elem_size = sizeof(((acm*)0)->hueGain);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = 1;
	obj->len_index = -1;
	obj->next_index = 28;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[28];
	strcpy(obj->name, "satGain");
	obj->type = J2S_TYPE_UINT_32;
	obj->flags = 0 ;
	obj->offset = (uintptr_t)&((acm*)0)->satGain;
	obj->elem_size = sizeof(((acm*)0)->satGain);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = 1;
	obj->len_index = -1;
	obj->next_index = -1;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[29];
	strcpy(obj->name, "gammaEnable");
	obj->type = J2S_TYPE_INT_8;
	obj->flags = 0 ;
	obj->offset = (uintptr_t)&((gamma*)0)->gammaEnable;
	obj->elem_size = sizeof(((gamma*)0)->gammaEnable);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = 1;
	obj->len_index = -1;
	obj->next_index = 30;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[30];
	strcpy(obj->name, "gammaTab_R");
	obj->type = J2S_TYPE_UINT_16;
	obj->flags = 0 | J2S_FLAG_ARRAY;
	obj->offset = (uintptr_t)&((gamma*)0)->gammaTab_R;
	obj->elem_size = sizeof(((gamma*)0)->gammaTab_R[0]);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = (sizeof(((gamma*)0)->gammaTab_R) / obj->elem_size);
	obj->len_index = -1;
	obj->next_index = 31;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[31];
	strcpy(obj->name, "gammaTab_G");
	obj->type = J2S_TYPE_UINT_16;
	obj->flags = 0 | J2S_FLAG_ARRAY;
	obj->offset = (uintptr_t)&((gamma*)0)->gammaTab_G;
	obj->elem_size = sizeof(((gamma*)0)->gammaTab_G[0]);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = (sizeof(((gamma*)0)->gammaTab_G) / obj->elem_size);
	obj->len_index = -1;
	obj->next_index = 32;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[32];
	strcpy(obj->name, "gammaTab_B");
	obj->type = J2S_TYPE_UINT_16;
	obj->flags = 0 | J2S_FLAG_ARRAY;
	obj->offset = (uintptr_t)&((gamma*)0)->gammaTab_B;
	obj->elem_size = sizeof(((gamma*)0)->gammaTab_B[0]);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = (sizeof(((gamma*)0)->gammaTab_B) / obj->elem_size);
	obj->len_index = -1;
	obj->next_index = -1;
	obj->struct_index = -1;
	obj->enum_index = -1;

	obj = &ctx->objs[33];
	strcpy(obj->name, "csc");
	obj->type = J2S_TYPE_STRUCT;
	obj->flags = 0 ;
	obj->offset = (uintptr_t)&((pq_tuning_param*)0)->csc;
	obj->elem_size = sizeof(((pq_tuning_param*)0)->csc);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = 1;
	obj->len_index = -1;
	obj->next_index = 34;
	obj->struct_index = 0;
	obj->enum_index = -1;

	obj = &ctx->objs[34];
	strcpy(obj->name, "dci");
	obj->type = J2S_TYPE_STRUCT;
	obj->flags = 0 ;
	obj->offset = (uintptr_t)&((pq_tuning_param*)0)->dci;
	obj->elem_size = sizeof(((pq_tuning_param*)0)->dci);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = 1;
	obj->len_index = -1;
	obj->next_index = 35;
	obj->struct_index = 1;
	obj->enum_index = -1;

	obj = &ctx->objs[35];
	strcpy(obj->name, "acm");
	obj->type = J2S_TYPE_STRUCT;
	obj->flags = 0 ;
	obj->offset = (uintptr_t)&((pq_tuning_param*)0)->acm;
	obj->elem_size = sizeof(((pq_tuning_param*)0)->acm);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = 1;
	obj->len_index = -1;
	obj->next_index = 36;
	obj->struct_index = 2;
	obj->enum_index = -1;

	obj = &ctx->objs[36];
	strcpy(obj->name, "gamma");
	obj->type = J2S_TYPE_STRUCT;
	obj->flags = 0 ;
	obj->offset = (uintptr_t)&((pq_tuning_param*)0)->gamma;
	obj->elem_size = sizeof(((pq_tuning_param*)0)->gamma);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = 1;
	obj->len_index = -1;
	obj->next_index = -1;
	obj->struct_index = 3;
	obj->enum_index = -1;

	obj = &ctx->objs[37];
	strcpy(obj->name, "pq_tuning_param");
	obj->type = J2S_TYPE_STRUCT;
	obj->flags = 0 ;
	obj->offset = (uintptr_t)&((pq_config*)0)->pq_tuning_param;
	obj->elem_size = sizeof(((pq_config*)0)->pq_tuning_param);
	obj->base_elem_size = obj->elem_size;
	obj->num_elem = 1;
	obj->len_index = -1;
	obj->next_index = -1;
	obj->struct_index = 4;
	obj->enum_index = -1;

	strcpy(ctx->structs[0].name, "csc");
	ctx->structs[0].child_index = 0;
	strcpy(ctx->structs[1].name, "dci");
	ctx->structs[1].child_index = 9;
	strcpy(ctx->structs[2].name, "acm");
	ctx->structs[2].child_index = 16;
	strcpy(ctx->structs[3].name, "gamma");
	ctx->structs[3].child_index = 29;
	strcpy(ctx->structs[4].name, "pq_tuning_param");
	ctx->structs[4].child_index = 33;
	strcpy(ctx->structs[5].name, "pq_config");
	ctx->structs[5].child_index = 37;
}
