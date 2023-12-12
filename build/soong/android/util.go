// Copyright 2015 Google Inc. All rights reserved.
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

package android

import (
	"fmt"
	"path/filepath"
	"reflect"
	"regexp"
	"runtime"
	"sort"
	"strings"
)

// CopyOf returns a new slice that has the same contents as s.
func CopyOf(s []string) []string {
	return append([]string(nil), s...)
}

// JoinWithPrefix prepends the prefix to each string in the list and
// returns them joined together with " " as separator.
func JoinWithPrefix(strs []string, prefix string) string {
	if len(strs) == 0 {
		return ""
	}

	var buf strings.Builder
	buf.WriteString(prefix)
	buf.WriteString(strs[0])
	for i := 1; i < len(strs); i++ {
		buf.WriteString(" ")
		buf.WriteString(prefix)
		buf.WriteString(strs[i])
	}
	return buf.String()
}

// JoinWithSuffix appends the suffix to each string in the list and
// returns them joined together with given separator.
func JoinWithSuffix(strs []string, suffix string, separator string) string {
	if len(strs) == 0 {
		return ""
	}

	var buf strings.Builder
	buf.WriteString(strs[0])
	buf.WriteString(suffix)
	for i := 1; i < len(strs); i++ {
		buf.WriteString(separator)
		buf.WriteString(strs[i])
		buf.WriteString(suffix)
	}
	return buf.String()
}

// SortedIntKeys returns the keys of the given integer-keyed map in the ascending order
// TODO(asmundak): once Go has generics, combine this with SortedStringKeys below.
func SortedIntKeys(m interface{}) []int {
	v := reflect.ValueOf(m)
	if v.Kind() != reflect.Map {
		panic(fmt.Sprintf("%#v is not a map", m))
	}
	keys := v.MapKeys()
	s := make([]int, 0, len(keys))
	for _, key := range keys {
		s = append(s, int(key.Int()))
	}
	sort.Ints(s)
	return s
}

// SorterStringKeys returns the keys of the given string-keyed map in the ascending order
func SortedStringKeys(m interface{}) []string {
	v := reflect.ValueOf(m)
	if v.Kind() != reflect.Map {
		panic(fmt.Sprintf("%#v is not a map", m))
	}
	keys := v.MapKeys()
	s := make([]string, 0, len(keys))
	for _, key := range keys {
		s = append(s, key.String())
	}
	sort.Strings(s)
	return s
}

// SortedStringMapValues returns the values of the string-values map in the ascending order
func SortedStringMapValues(m interface{}) []string {
	v := reflect.ValueOf(m)
	if v.Kind() != reflect.Map {
		panic(fmt.Sprintf("%#v is not a map", m))
	}
	keys := v.MapKeys()
	s := make([]string, 0, len(keys))
	for _, key := range keys {
		s = append(s, v.MapIndex(key).String())
	}
	sort.Strings(s)
	return s
}

// IndexList returns the index of the first occurrence of the given string in the list or -1
func IndexList(s string, list []string) int {
	for i, l := range list {
		if l == s {
			return i
		}
	}

	return -1
}

// InList checks if the string belongs to the list
func InList(s string, list []string) bool {
	return IndexList(s, list) != -1
}

// Returns true if the given string s is prefixed with any string in the given prefix list.
func HasAnyPrefix(s string, prefixList []string) bool {
	for _, prefix := range prefixList {
		if strings.HasPrefix(s, prefix) {
			return true
		}
	}
	return false
}

// Returns true if any string in the given list has the given substring.
func SubstringInList(list []string, substr string) bool {
	for _, s := range list {
		if strings.Contains(s, substr) {
			return true
		}
	}
	return false
}

// Returns true if any string in the given list has the given prefix.
func PrefixInList(list []string, prefix string) bool {
	for _, s := range list {
		if strings.HasPrefix(s, prefix) {
			return true
		}
	}
	return false
}

// Returns true if any string in the given list has the given suffix.
func SuffixInList(list []string, suffix string) bool {
	for _, s := range list {
		if strings.HasSuffix(s, suffix) {
			return true
		}
	}
	return false
}

// IndexListPred returns the index of the element which in the given `list` satisfying the predicate, or -1 if there is no such element.
func IndexListPred(pred func(s string) bool, list []string) int {
	for i, l := range list {
		if pred(l) {
			return i
		}
	}

	return -1
}

// FilterList divides the string list into two lists: one with the strings belonging
// to the given filter list, and the other with the remaining ones
func FilterList(list []string, filter []string) (remainder []string, filtered []string) {
	// InList is O(n). May be worth using more efficient lookup for longer lists.
	for _, l := range list {
		if InList(l, filter) {
			filtered = append(filtered, l)
		} else {
			remainder = append(remainder, l)
		}
	}

	return
}

// FilterListPred returns the elements of the given list for which the predicate
// returns true. Order is kept.
func FilterListPred(list []string, pred func(s string) bool) (filtered []string) {
	for _, l := range list {
		if pred(l) {
			filtered = append(filtered, l)
		}
	}
	return
}

// RemoveListFromList removes the strings belonging to the filter list from the
// given list and returns the result
func RemoveListFromList(list []string, filter_out []string) (result []string) {
	result = make([]string, 0, len(list))
	for _, l := range list {
		if !InList(l, filter_out) {
			result = append(result, l)
		}
	}
	return
}

// RemoveFromList removes given string from the string list.
func RemoveFromList(s string, list []string) (bool, []string) {
	result := make([]string, 0, len(list))
	var removed bool
	for _, item := range list {
		if item != s {
			result = append(result, item)
		} else {
			removed = true
		}
	}
	return removed, result
}

// FirstUniqueStrings returns all unique elements of a slice of strings, keeping the first copy of
// each.  It modifies the slice contents in place, and returns a subslice of the original slice.
func FirstUniqueStrings(list []string) []string {
	// 128 was chosen based on BenchmarkFirstUniqueStrings results.
	if len(list) > 128 {
		return firstUniqueStringsMap(list)
	}
	return firstUniqueStringsList(list)
}

func firstUniqueStringsList(list []string) []string {
	k := 0
outer:
	for i := 0; i < len(list); i++ {
		for j := 0; j < k; j++ {
			if list[i] == list[j] {
				continue outer
			}
		}
		list[k] = list[i]
		k++
	}
	return list[:k]
}

func firstUniqueStringsMap(list []string) []string {
	k := 0
	seen := make(map[string]bool, len(list))
	for i := 0; i < len(list); i++ {
		if seen[list[i]] {
			continue
		}
		seen[list[i]] = true
		list[k] = list[i]
		k++
	}
	return list[:k]
}

// LastUniqueStrings returns all unique elements of a slice of strings, keeping the last copy of
// each.  It modifies the slice contents in place, and returns a subslice of the original slice.
func LastUniqueStrings(list []string) []string {
	totalSkip := 0
	for i := len(list) - 1; i >= totalSkip; i-- {
		skip := 0
		for j := i - 1; j >= totalSkip; j-- {
			if list[i] == list[j] {
				skip++
			} else {
				list[j+skip] = list[j]
			}
		}
		totalSkip += skip
	}
	return list[totalSkip:]
}

// SortedUniqueStrings returns what the name says
func SortedUniqueStrings(list []string) []string {
	unique := FirstUniqueStrings(list)
	sort.Strings(unique)
	return unique
}

// checkCalledFromInit panics if a Go package's init function is not on the
// call stack.
func checkCalledFromInit() {
	for skip := 3; ; skip++ {
		_, funcName, ok := callerName(skip)
		if !ok {
			panic("not called from an init func")
		}

		if funcName == "init" || strings.HasPrefix(funcName, "init·") ||
			strings.HasPrefix(funcName, "init.") {
			return
		}
	}
}

// A regex to find a package path within a function name. It finds the shortest string that is
// followed by '.' and doesn't have any '/'s left.
var pkgPathRe = regexp.MustCompile(`^(.*?)\.([^/]+)$`)

// callerName returns the package path and function name of the calling
// function.  The skip argument has the same meaning as the skip argument of
// runtime.Callers.
func callerName(skip int) (pkgPath, funcName string, ok bool) {
	var pc [1]uintptr
	n := runtime.Callers(skip+1, pc[:])
	if n != 1 {
		return "", "", false
	}

	f := runtime.FuncForPC(pc[0]).Name()
	s := pkgPathRe.FindStringSubmatch(f)
	if len(s) < 3 {
		panic(fmt.Errorf("failed to extract package path and function name from %q", f))
	}

	return s[1], s[2], true
}

// GetNumericSdkVersion removes the first occurrence of system_ in a string,
// which is assumed to be something like "system_1.2.3"
func GetNumericSdkVersion(v string) string {
	return strings.Replace(v, "system_", "", 1)
}

// copied from build/kati/strutil.go
func substPattern(pat, repl, str string) string {
	ps := strings.SplitN(pat, "%", 2)
	if len(ps) != 2 {
		if str == pat {
			return repl
		}
		return str
	}
	in := str
	trimmed := str
	if ps[0] != "" {
		trimmed = strings.TrimPrefix(in, ps[0])
		if trimmed == in {
			return str
		}
	}
	in = trimmed
	if ps[1] != "" {
		trimmed = strings.TrimSuffix(in, ps[1])
		if trimmed == in {
			return str
		}
	}

	rs := strings.SplitN(repl, "%", 2)
	if len(rs) != 2 {
		return repl
	}
	return rs[0] + trimmed + rs[1]
}

// copied from build/kati/strutil.go
func matchPattern(pat, str string) bool {
	i := strings.IndexByte(pat, '%')
	if i < 0 {
		return pat == str
	}
	return strings.HasPrefix(str, pat[:i]) && strings.HasSuffix(str, pat[i+1:])
}

var shlibVersionPattern = regexp.MustCompile("(?:\\.\\d+(?:svn)?)+")

// splitFileExt splits a file name into root, suffix and ext. root stands for the file name without
// the file extension and the version number (e.g. "libexample"). suffix stands for the
// concatenation of the file extension and the version number (e.g. ".so.1.0"). ext stands for the
// file extension after the version numbers are trimmed (e.g. ".so").
func SplitFileExt(name string) (string, string, string) {
	// Extract and trim the shared lib version number if the file name ends with dot digits.
	suffix := ""
	matches := shlibVersionPattern.FindAllStringIndex(name, -1)
	if len(matches) > 0 {
		lastMatch := matches[len(matches)-1]
		if lastMatch[1] == len(name) {
			suffix = name[lastMatch[0]:lastMatch[1]]
			name = name[0:lastMatch[0]]
		}
	}

	// Extract the file name root and the file extension.
	ext := filepath.Ext(name)
	root := strings.TrimSuffix(name, ext)
	suffix = ext + suffix

	return root, suffix, ext
}

// ShardPaths takes a Paths, and returns a slice of Paths where each one has at most shardSize paths.
func ShardPaths(paths Paths, shardSize int) []Paths {
	if len(paths) == 0 {
		return nil
	}
	ret := make([]Paths, 0, (len(paths)+shardSize-1)/shardSize)
	for len(paths) > shardSize {
		ret = append(ret, paths[0:shardSize])
		paths = paths[shardSize:]
	}
	if len(paths) > 0 {
		ret = append(ret, paths)
	}
	return ret
}

// ShardString takes a string and returns a slice of strings where the length of each one is
// at most shardSize.
func ShardString(s string, shardSize int) []string {
	if len(s) == 0 {
		return nil
	}
	ret := make([]string, 0, (len(s)+shardSize-1)/shardSize)
	for len(s) > shardSize {
		ret = append(ret, s[0:shardSize])
		s = s[shardSize:]
	}
	if len(s) > 0 {
		ret = append(ret, s)
	}
	return ret
}

// ShardStrings takes a slice of strings, and returns a slice of slices of strings where each one has at most shardSize
// elements.
func ShardStrings(s []string, shardSize int) [][]string {
	if len(s) == 0 {
		return nil
	}
	ret := make([][]string, 0, (len(s)+shardSize-1)/shardSize)
	for len(s) > shardSize {
		ret = append(ret, s[0:shardSize])
		s = s[shardSize:]
	}
	if len(s) > 0 {
		ret = append(ret, s)
	}
	return ret
}

// CheckDuplicate checks if there are duplicates in given string list.
// If there are, it returns first such duplicate and true.
func CheckDuplicate(values []string) (duplicate string, found bool) {
	seen := make(map[string]string)
	for _, v := range values {
		if duplicate, found = seen[v]; found {
			return duplicate, true
		}
		seen[v] = v
	}
	return "", false
}
