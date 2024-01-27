/*
 * Copyright (C) 2020, 2022 ARM Limited. All rights reserved.
 *
 * Copyright (C) 2008 The Android Open Source Project
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
#pragma once

#include <inttypes.h>
#include <string>
#include "gralloc/formats.h"

class producers_t;
class consumers_t;

bool ip_support_feature(mali_gralloc_ip producers, mali_gralloc_ip consumers, const char *name);

/**
 * @brief Class that represents a set of IPs (CPU, GPU, DPU, VPU).
 *
 * This class represents a set of IPs. It provides a type safe alternative to using mali_gralloc_ip
 * directly. See in particular the derived types producer_t and consumer_t.
 * Using these types provides type safety, as it is not possible to accidentally exchange
 * consumers and producers. It also makes the code more readable.
 */
class ip_t
{
public:
	/**
	 * @brief Check whether a feature is supported by all provided producers and consumers.
	 *
	 * @param producers A set of producers.
	 * @param consumers A set of consumers.
	 * @param name Name of the feature.
	 * @return Whether the feature @p name is supported by all of @p producers and @p consumers.
	 *   If @p producers or @p consumers are empty, then they are ignored.
	 *   For example, if @p producers is empty then this function checks whether @p name is
	 *   supported by all consumers only. If @p producers and @p consumers are both empty, this
	 *   function returns unconditionally @c true. Similarly, producers and consumers that are
	 *   not present (see ip_t::present for a definition of "present") are also ignored.
	 */
	static bool support(producers_t producers, consumers_t consumers, const char *name);

	/**
	 * @brief Check whether the provided IPs are present in the system.
	 *
	 * @param ips The IP set to check.
	 * @return Whether all the IPs in @p ips are present in the system. An IP is considered present
	 *   when the Gralloc configuration files explicitly provide the capabilities for that IP.
	 */
	static bool present(ip_t ips);

	ip_t() = default;

	ip_t(mali_gralloc_ip ip)
	    : m_value(ip)
	{
	}

	bool empty() const
	{
		return m_value == 0;
	}

	bool contains(mali_gralloc_ip ip) const
	{
		return (ip & m_value);
	}

	void add(mali_gralloc_ip ip)
	{
		m_value |= ip;
	}

	void remove(mali_gralloc_ip ip)
	{
		m_value &= ~ip;
	}

	mali_gralloc_ip get() const
	{
		return m_value;
	}

private:
	mali_gralloc_ip m_value = MALI_GRALLOC_IP_NONE;
};

/**
 * @brief Set of producers.
 */
class producers_t : public ip_t
{
public:
	using ip_t::ip_t;

	bool support(const char *name) const
	{
		return ip_support_feature(get(), MALI_GRALLOC_IP_NONE, name);
	}
};

/**
 * @brief Set of consumers.
 */
class consumers_t : public ip_t
{
public:
	using ip_t::ip_t;

	bool support(const char *name) const
	{
		return ip_support_feature(MALI_GRALLOC_IP_NONE, get(), name);
	}
};

inline bool ip_t::support(producers_t producers, consumers_t consumers, const char *name)
{
	return ip_support_feature(producers.get(), consumers.get(), name);
}

inline bool ip_t::present(ip_t ips)
{
	for (mali_gralloc_ip ip = 1; ip <= ips.get() && ip != 0; ip <<= 1)
	{
		/* The call to ip_support_feature() returns true iff:
		 * - ip is not found in the configuration files
		 * - ip is explictly marked as disabled in the configuration files for both read/write
		 */
		if (ips.contains(ip) && ip_support_feature(ip, ip, "DISABLED"))
		{
			return false;
		}
	}
	return true;
}
