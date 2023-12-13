bin_path := $(notdir $(HOST_OUT_EXECUTABLES))

fetcher_bin := $(HOST_OUT)/$(bin_path)/fetch_cvd

.PHONY: host_fetcher
host_fetcher: $(fetcher_bin)

# Build this by default when a developer types make
droidcore: $(fetcher_bin)

# Build and store them on the build server.
$(call dist-for-goals, dist_files, $(fetcher_bin))
