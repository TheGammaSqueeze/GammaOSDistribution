#include <iostream>

#include "gc/collector_type.h"

// This was automatically generated by art/tools/generate_operator_out.py --- do not edit!
namespace art {
namespace gc {
std::ostream& operator<<(std::ostream& os, CollectorType rhs) {
  switch (rhs) {
    case kCollectorTypeNone: os << "CollectorTypeNone"; break;
    case kCollectorTypeMS: os << "CollectorTypeMS"; break;
    case kCollectorTypeCMS: os << "CollectorTypeCMS"; break;
    case kCollectorTypeSS: os << "CollectorTypeSS"; break;
    case kCollectorTypeHeapTrim: os << "CollectorTypeHeapTrim"; break;
    case kCollectorTypeCC: os << "CollectorTypeCC"; break;
    case kCollectorTypeCCBackground: os << "CollectorTypeCCBackground"; break;
    case kCollectorTypeInstrumentation: os << "CollectorTypeInstrumentation"; break;
    case kCollectorTypeAddRemoveAppImageSpace: os << "CollectorTypeAddRemoveAppImageSpace"; break;
    case kCollectorTypeDebugger: os << "CollectorTypeDebugger"; break;
    case kCollectorTypeHomogeneousSpaceCompact: os << "CollectorTypeHomogeneousSpaceCompact"; break;
    case kCollectorTypeClassLinker: os << "CollectorTypeClassLinker"; break;
    case kCollectorTypeJitCodeCache: os << "CollectorTypeJitCodeCache"; break;
    case kCollectorTypeHprof: os << "CollectorTypeHprof"; break;
    case kCollectorTypeAddRemoveSystemWeakHolder: os << "CollectorTypeAddRemoveSystemWeakHolder"; break;
    case kCollectorTypeGetObjectsAllocated: os << "CollectorTypeGetObjectsAllocated"; break;
    case kCollectorTypeCriticalSection: os << "CollectorTypeCriticalSection"; break;
    default: os << "CollectorType[" << static_cast<int>(rhs) << "]"; break;
  }
  return os;
}
}  // namespace gc
}  // namespace art

