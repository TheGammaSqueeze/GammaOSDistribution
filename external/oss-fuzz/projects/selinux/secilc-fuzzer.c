/*
# Copyright 2020 Google Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
################################################################################
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <getopt.h>
#include <sys/stat.h>

#include <sepol/cil/cil.h>
#include <sepol/policydb.h>

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
	enum cil_log_level log_level = CIL_ERR;
	struct sepol_policy_file *pf = NULL;
	FILE *dev_null = NULL;
	int target = SEPOL_TARGET_SELINUX;
	int disable_dontaudit = 0;
	int multiple_decls = 0;
	int disable_neverallow = 0;
	int preserve_tunables = 0;
	int policyvers = POLICYDB_VERSION_MAX;
	int mls = -1;
	int attrs_expand_generated = 0;
	struct cil_db *db = NULL;
	sepol_policydb_t *pdb = NULL;

	cil_set_log_level(log_level);

	cil_db_init(&db);
	cil_set_disable_dontaudit(db, disable_dontaudit);
	cil_set_multiple_decls(db, multiple_decls);
	cil_set_disable_neverallow(db, disable_neverallow);
	cil_set_preserve_tunables(db, preserve_tunables);
	cil_set_mls(db, mls);
	cil_set_target_platform(db, target);
	cil_set_policy_version(db, policyvers);
	cil_set_attrs_expand_generated(db, attrs_expand_generated);

	if (cil_add_file(db, "fuzz", data, size) != SEPOL_OK)
		goto exit;

	if (cil_compile(db) != SEPOL_OK)
		goto exit;

	if (cil_build_policydb(db, &pdb) != SEPOL_OK)
		goto exit;

	if (sepol_policydb_optimize(pdb) != SEPOL_OK)
		goto exit;

	dev_null = fopen("/dev/null", "w");
	if (dev_null == NULL)
		goto exit;

	if (sepol_policy_file_create(&pf) != 0)
		goto exit;

	sepol_policy_file_set_fp(pf, dev_null);

	if (sepol_policydb_write(pdb, pf) != 0)
		goto exit;
exit:
	if (dev_null != NULL)
		fclose(dev_null);

	cil_db_destroy(&db);
	sepol_policydb_free(pdb);
	sepol_policy_file_free(pf);
	return 0;
}
