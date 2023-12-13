// Copyright 2021, The Android Open Source Project
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

//! Provides interface for logging events to binary log buffers.

use log_event_list_bindgen as log_bindgen;
use std::os::raw::c_char;

pub use log_bindgen::log_id_LOG_ID_SECURITY as LogIdSecurity;

/// Whether security logging is enabled.
fn security_log_enabled() -> bool {
    // The call doesn't require any preconditions and only returns an int, so must be safe.
    unsafe {
        log_bindgen::__android_log_security() != 0
    }
}

/// Event log context.
pub struct LogContext {
    ctx: log_bindgen::android_log_context,
    log_type: log_bindgen::log_id
}

/// Log context is essentially a buffer with some associated state. All data that is appended to
/// the context is copied into the buffers, no references are ever stored.
unsafe impl Send for LogContext {}

impl LogContext {
    /// Creates a context for a given event tag.
    pub fn new(log_type: log_bindgen::log_id, tag: u32) -> Option<LogContext> {
        if log_type == log_bindgen::log_id_LOG_ID_SECURITY && !security_log_enabled() {
            return None;
        }

        // The method returns a pointer that is stored and always freed exactly once via Drop below.
        let ctx = unsafe { log_bindgen::create_android_logger(tag) };
        if !ctx.is_null() {
            Some(LogContext{ ctx, log_type })
        } else {
            None
        }
    }

    /// Appends an i32 to the context.
    pub fn append_i32(self, data: i32) -> Self {
        // This will only be called on a non-null pointer returned from create_android_logger
        // previously, so should be safe.
        unsafe { log_bindgen::android_log_write_int32(self.ctx, data) };
        self
    }

    /// Append a string to the context.
    pub fn append_str(self, data: &str) -> Self {
        // This will only be called on a non-null pointer returned from create_android_logger
        // previously, and the function will only read data.len() characters from the str, the
        // pointer itself won't be stored, so should be safe.
        unsafe {
            log_bindgen::android_log_write_string8_len(
                self.ctx, data.as_ptr() as *const c_char, data.len())
        };
        self
    }

    /// Writes the context to a given buffer type and consumes the context.
    pub fn write(self) {
        // This will only be called on a non-null pointer returned from create_android_logger
        // previously, so should be safe.
        unsafe { log_bindgen::android_log_write_list(self.ctx, self.log_type) };
    }
}

impl Drop for LogContext {
    fn drop(&mut self) {
        // This will only be called on a non-null pointer returned from create_android_logger
        // previously, so should be safe.
        unsafe { log_bindgen::android_log_destroy(&mut self.ctx) };
    }
}
