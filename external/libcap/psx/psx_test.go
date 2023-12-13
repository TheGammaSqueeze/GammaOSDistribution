package psx

import (
	"runtime"
	"syscall"
	"testing"
)

func TestSyscall3(t *testing.T) {
	want := syscall.Getpid()
	if got, _, err := Syscall3(syscall.SYS_GETPID, 0, 0, 0); err != 0 {
		t.Errorf("failed to get PID via libpsx: %v", err)
	} else if int(got) != want {
		t.Errorf("pid mismatch: got=%d want=%d", got, want)
	}
	if got, _, err := Syscall3(syscall.SYS_CAPGET, 0, 0, 0); err != 14 {
		t.Errorf("malformed capget returned %d: %v (want 14: %v)", err, err, syscall.Errno(14))
	} else if ^got != 0 {
		t.Errorf("malformed capget did not return -1, got=%d", got)
	}
}

func TestSyscall6(t *testing.T) {
	want := syscall.Getpid()
	if got, _, err := Syscall6(syscall.SYS_GETPID, 0, 0, 0, 0, 0, 0); err != 0 {
		t.Errorf("failed to get PID via libpsx: %v", err)
	} else if int(got) != want {
		t.Errorf("pid mismatch: got=%d want=%d", got, want)
	}
	if got, _, err := Syscall6(syscall.SYS_CAPGET, 0, 0, 0, 0, 0, 0); err != 14 {
		t.Errorf("malformed capget errno %d: %v (want 14: %v)", err, err, syscall.Errno(14))
	} else if ^got != 0 {
		t.Errorf("malformed capget did not return -1, got=%d", got)
	}
}

// killAThread locks the goroutine to a thread and exits. This has the
// effect of making the go runtime terminate the thread.
func killAThread(c <-chan struct{}) {
	runtime.LockOSThread()
	<-c
}

// Test to confirm no regression against:
//
//   https://github.com/golang/go/issues/42494
func TestThreadChurn(t *testing.T) {
	const prSetKeepCaps = 8

	for j := 0; j < 4; j++ {
		kill := (j & 1) != 0
		sysc := (j & 2) != 0
		t.Logf("[%d] testing kill=%v, sysc=%v", j, kill, sysc)
		for i := 50; i > 0; i-- {
			if kill {
				c := make(chan struct{})
				go killAThread(c)
				close(c)
			}
			if sysc {
				if _, _, e := Syscall3(syscall.SYS_PRCTL, prSetKeepCaps, uintptr(i&1), 0); e != 0 {
					t.Fatalf("[%d] psx:prctl(SET_KEEPCAPS, %d) failed: %v", i, i&1, syscall.Errno(e))
				}
			}
		}
		t.Logf("[%d] PASSED kill=%v, sysc=%v", j, kill, sysc)
	}
}
