// Copyright 2018 Google Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Package metrics represents the metrics system for Android Platform Build Systems.
package metrics

// This is the main heart of the metrics system for Android Platform Build Systems.
// The starting of the soong_ui (cmd/soong_ui/main.go), the metrics system is
// initialized by the invocation of New and is then stored in the context
// (ui/build/context.go) to be used throughout the system. During the build
// initialization phase, several functions in this file are invoked to store
// information such as the environment, build configuration and build metadata.
// There are several scoped code that has Begin() and defer End() functions
// that captures the metrics and is them added as a perfInfo into the set
// of the collected metrics. Finally, when soong_ui has finished the build,
// the defer Dump function is invoked to store the collected metrics to the
// raw protobuf file in the $OUT directory.
//
// There is one additional step that occurs after the raw protobuf file is written.
// If the configuration environment variable ANDROID_ENABLE_METRICS_UPLOAD is
// set with the path, the raw protobuf file is uploaded to the destination. See
// ui/build/upload.go for more details. The filename of the raw protobuf file
// and the list of files to be uploaded is defined in cmd/soong_ui/main.go.
//
// See ui/metrics/event.go for the explanation of what an event is and how
// the metrics system is a stack based system.

import (
	"io/ioutil"
	"os"
	"runtime"
	"strings"
	"time"

	"github.com/golang/protobuf/proto"

	"android/soong/ui/metrics/metrics_proto"
)

const (
	// Below is a list of names passed in to the Begin tracing functions. These
	// names are used to group a set of metrics.

	// Setup and tear down of the build systems.
	RunSetupTool    = "setup"
	RunShutdownTool = "shutdown"
	TestRun         = "test"

	// List of build system tools.
	RunSoong     = "soong"
	PrimaryNinja = "ninja"
	RunKati      = "kati"
	RunBazel     = "bazel"

	// Overall build from building the graph to building the target.
	Total = "total"
)

// Metrics is a struct that stores collected metrics during the course
// of a build which later is dumped to a MetricsBase protobuf file.
// See ui/metrics/metrics_proto/metrics.proto for further details
// on what information is collected.
type Metrics struct {
	// The protobuf message that is later written to the file.
	metrics soong_metrics_proto.MetricsBase

	// A list of pending build events.
	EventTracer *EventTracer
}

// New returns a pointer of Metrics to store a set of metrics.
func New() (metrics *Metrics) {
	m := &Metrics{
		metrics:     soong_metrics_proto.MetricsBase{},
		EventTracer: &EventTracer{},
	}
	return m
}

// SetTimeMetrics stores performance information from an executed block of
// code.
func (m *Metrics) SetTimeMetrics(perf soong_metrics_proto.PerfInfo) {
	switch perf.GetName() {
	case RunKati:
		m.metrics.KatiRuns = append(m.metrics.KatiRuns, &perf)
	case RunSoong:
		m.metrics.SoongRuns = append(m.metrics.SoongRuns, &perf)
	case RunBazel:
		m.metrics.BazelRuns = append(m.metrics.BazelRuns, &perf)
	case PrimaryNinja:
		m.metrics.NinjaRuns = append(m.metrics.NinjaRuns, &perf)
	case RunSetupTool:
		m.metrics.SetupTools = append(m.metrics.SetupTools, &perf)
	case Total:
		m.metrics.Total = &perf
	}
}

// BuildConfig stores information about the build configuration.
func (m *Metrics) BuildConfig(b *soong_metrics_proto.BuildConfig) {
	m.metrics.BuildConfig = b
}

// SystemResourceInfo stores information related to the host system such
// as total CPU and memory.
func (m *Metrics) SystemResourceInfo(b *soong_metrics_proto.SystemResourceInfo) {
	m.metrics.SystemResourceInfo = b
}

// SetMetadataMetrics sets information about the build such as the target
// product, host architecture and out directory.
func (m *Metrics) SetMetadataMetrics(metadata map[string]string) {
	for k, v := range metadata {
		switch k {
		case "BUILD_ID":
			m.metrics.BuildId = proto.String(v)
		case "PLATFORM_VERSION_CODENAME":
			m.metrics.PlatformVersionCodename = proto.String(v)
		case "TARGET_PRODUCT":
			m.metrics.TargetProduct = proto.String(v)
		case "TARGET_BUILD_VARIANT":
			switch v {
			case "user":
				m.metrics.TargetBuildVariant = soong_metrics_proto.MetricsBase_USER.Enum()
			case "userdebug":
				m.metrics.TargetBuildVariant = soong_metrics_proto.MetricsBase_USERDEBUG.Enum()
			case "eng":
				m.metrics.TargetBuildVariant = soong_metrics_proto.MetricsBase_ENG.Enum()
			}
		case "TARGET_ARCH":
			m.metrics.TargetArch = arch(v)
		case "TARGET_ARCH_VARIANT":
			m.metrics.TargetArchVariant = proto.String(v)
		case "TARGET_CPU_VARIANT":
			m.metrics.TargetCpuVariant = proto.String(v)
		case "HOST_ARCH":
			m.metrics.HostArch = arch(v)
		case "HOST_2ND_ARCH":
			m.metrics.Host_2NdArch = arch(v)
		case "HOST_OS_EXTRA":
			m.metrics.HostOsExtra = proto.String(v)
		case "HOST_CROSS_OS":
			m.metrics.HostCrossOs = proto.String(v)
		case "HOST_CROSS_ARCH":
			m.metrics.HostCrossArch = proto.String(v)
		case "HOST_CROSS_2ND_ARCH":
			m.metrics.HostCross_2NdArch = proto.String(v)
		case "OUT_DIR":
			m.metrics.OutDir = proto.String(v)
		}
	}
}

// arch returns the corresponding MetricsBase_Arch based on the string
// parameter.
func arch(a string) *soong_metrics_proto.MetricsBase_Arch {
	switch a {
	case "arm":
		return soong_metrics_proto.MetricsBase_ARM.Enum()
	case "arm64":
		return soong_metrics_proto.MetricsBase_ARM64.Enum()
	case "x86":
		return soong_metrics_proto.MetricsBase_X86.Enum()
	case "x86_64":
		return soong_metrics_proto.MetricsBase_X86_64.Enum()
	default:
		return soong_metrics_proto.MetricsBase_UNKNOWN.Enum()
	}
}

// SetBuildDateTime sets the build date and time. The value written
// to the protobuf file is in seconds.
func (m *Metrics) SetBuildDateTime(buildTimestamp time.Time) {
	m.metrics.BuildDateTimestamp = proto.Int64(buildTimestamp.UnixNano() / int64(time.Second))
}

// SetBuildCommand adds the build command specified by the user to the
// list of collected metrics.
func (m *Metrics) SetBuildCommand(cmd []string) {
	m.metrics.BuildCommand = proto.String(strings.Join(cmd, " "))
}

// Dump exports the collected metrics from the executed build to the file at
// out path.
func (m *Metrics) Dump(out string) error {
	// ignore the error if the hostname could not be retrieved as it
	// is not a critical metric to extract.
	if hostname, err := os.Hostname(); err == nil {
		m.metrics.Hostname = proto.String(hostname)
	}
	m.metrics.HostOs = proto.String(runtime.GOOS)

	return save(&m.metrics, out)
}

// SetSoongBuildMetrics sets the metrics collected from the soong_build
// execution.
func (m *Metrics) SetSoongBuildMetrics(metrics *soong_metrics_proto.SoongBuildMetrics) {
	m.metrics.SoongBuildMetrics = metrics
}

// A CriticalUserJourneysMetrics is a struct that contains critical user journey
// metrics. These critical user journeys are defined under cuj/cuj.go file.
type CriticalUserJourneysMetrics struct {
	// A list of collected CUJ metrics.
	cujs soong_metrics_proto.CriticalUserJourneysMetrics
}

// NewCriticalUserJourneyMetrics returns a pointer of CriticalUserJourneyMetrics
// to capture CUJs metrics.
func NewCriticalUserJourneysMetrics() *CriticalUserJourneysMetrics {
	return &CriticalUserJourneysMetrics{}
}

// Add adds a set of collected metrics from an executed critical user journey.
func (c *CriticalUserJourneysMetrics) Add(name string, metrics *Metrics) {
	c.cujs.Cujs = append(c.cujs.Cujs, &soong_metrics_proto.CriticalUserJourneyMetrics{
		Name:    proto.String(name),
		Metrics: &metrics.metrics,
	})
}

// Dump saves the collected CUJs metrics to the raw protobuf file.
func (c *CriticalUserJourneysMetrics) Dump(filename string) (err error) {
	return save(&c.cujs, filename)
}

// save takes a protobuf message, marshals to an array of bytes
// and is then saved to a file.
func save(pb proto.Message, filename string) (err error) {
	data, err := proto.Marshal(pb)
	if err != nil {
		return err
	}

	tempFilename := filename + ".tmp"
	if err := ioutil.WriteFile(tempFilename, []byte(data), 0644 /* rw-r--r-- */); err != nil {
		return err
	}

	if err := os.Rename(tempFilename, filename); err != nil {
		return err
	}

	return nil
}
