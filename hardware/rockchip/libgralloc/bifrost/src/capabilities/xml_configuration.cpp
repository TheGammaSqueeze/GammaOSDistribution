/*
 * Copyright (C) 2022 ARM Limited. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "xml_configuration.h"

static const std::string xml_base_path = "/vendor/etc/gralloc/";

ip_capability::ip_capability(mali_gralloc_ip ip, const char *base_name)
    : ip_capability(ip, base_name, xml_base_path)
{
}

ip_capability::ip_capability(mali_gralloc_ip ip, const char *base_name, std::string_view base_path)
    : m_ip(ip)
    , m_path(std::string(base_path) + base_name + ".xml")
    , m_caps(capabilities_type::readCapabilities(m_path.c_str()))
{
	if (!m_caps.has_value())
	{
		MALI_GRALLOC_LOGE("Failed to read capabilities from %s", m_path.c_str());
	}
	else
	{
		MALI_GRALLOC_LOGV("Read caps from %s", m_path.c_str());
	}
}

bool ip_capability::is_feature_supported(const std::string &feature_name, permission_t permission)
{
	for (auto &feature : m_caps->getFeature())
	{
		if (feature.getName() == feature_name)
		{
			auto &xml_permission = feature.getPermission();
			bool readable = false;
			bool writeable = false;
			switch (xml_permission)
			{
			case capabilities_type::Permission::RW:
				readable = true;
				writeable = true;
				break;
			case capabilities_type::Permission::RO:
				readable = true;
				break;
			case capabilities_type::Permission::WO:
				writeable = true;
				break;
			case capabilities_type::Permission::NO:
				break;
			default:
				MALI_GRALLOC_LOGE("Invalid capabilities from %s", m_path.c_str());
			}
			switch (permission)
			{
			case permission_t::read:
				MALI_GRALLOC_LOGV("%s: getReadable(): %d.", feature_name.c_str(), readable);
				return readable;
			case permission_t::write:
				MALI_GRALLOC_LOGV("%s: getWritable(): %d.", feature_name.c_str(), writeable);
				return writeable;
			}
		}
	}

	return false;
}
