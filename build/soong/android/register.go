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
	"reflect"

	"github.com/google/blueprint"
)

// A sortable component is one whose registration order affects the order in which it is executed
// and so affects the behavior of the build system. As a result it is important for the order in
// which they are registered during tests to match the order used at runtime and so the test
// infrastructure will sort them to match.
//
// The sortable components are mutators, singletons and pre-singletons. Module types are not
// sortable because their order of registration does not affect the runtime behavior.
type sortableComponent interface {
	// componentName returns the name of the component.
	//
	// Uniquely identifies the components within the set of components used at runtimr and during
	// tests.
	componentName() string

	// register registers this component in the supplied context.
	register(ctx *Context)
}

type sortableComponents []sortableComponent

// registerAll registers all components in this slice with the supplied context.
func (r sortableComponents) registerAll(ctx *Context) {
	for _, c := range r {
		c.register(ctx)
	}
}

type moduleType struct {
	name    string
	factory ModuleFactory
}

func (t moduleType) register(ctx *Context) {
	ctx.RegisterModuleType(t.name, ModuleFactoryAdaptor(t.factory))
}

var moduleTypes []moduleType
var moduleTypesForDocs = map[string]reflect.Value{}

type singleton struct {
	// True if this should be registered as a pre-singleton, false otherwise.
	pre bool

	name    string
	factory SingletonFactory
}

func newSingleton(name string, factory SingletonFactory) singleton {
	return singleton{false, name, factory}
}

func newPreSingleton(name string, factory SingletonFactory) singleton {
	return singleton{true, name, factory}
}

func (s singleton) componentName() string {
	return s.name
}

func (s singleton) register(ctx *Context) {
	adaptor := SingletonFactoryAdaptor(ctx, s.factory)
	if s.pre {
		ctx.RegisterPreSingletonType(s.name, adaptor)
	} else {
		ctx.RegisterSingletonType(s.name, adaptor)
	}
}

var _ sortableComponent = singleton{}

var singletons sortableComponents
var preSingletons sortableComponents

type mutator struct {
	name            string
	bottomUpMutator blueprint.BottomUpMutator
	topDownMutator  blueprint.TopDownMutator
	parallel        bool
}

var _ sortableComponent = &mutator{}

type ModuleFactory func() Module

// ModuleFactoryAdaptor wraps a ModuleFactory into a blueprint.ModuleFactory by converting a Module
// into a blueprint.Module and a list of property structs
func ModuleFactoryAdaptor(factory ModuleFactory) blueprint.ModuleFactory {
	return func() (blueprint.Module, []interface{}) {
		module := factory()
		return module, module.GetProperties()
	}
}

type SingletonFactory func() Singleton

// SingletonFactoryAdaptor wraps a SingletonFactory into a blueprint.SingletonFactory by converting
// a Singleton into a blueprint.Singleton
func SingletonFactoryAdaptor(ctx *Context, factory SingletonFactory) blueprint.SingletonFactory {
	return func() blueprint.Singleton {
		singleton := factory()
		if makevars, ok := singleton.(SingletonMakeVarsProvider); ok {
			registerSingletonMakeVarsProvider(ctx.config, makevars)
		}
		return &singletonAdaptor{Singleton: singleton}
	}
}

func RegisterModuleType(name string, factory ModuleFactory) {
	moduleTypes = append(moduleTypes, moduleType{name, factory})
	RegisterModuleTypeForDocs(name, reflect.ValueOf(factory))
}

// RegisterModuleTypeForDocs associates a module type name with a reflect.Value of the factory
// function that has documentation for the module type.  It is normally called automatically
// by RegisterModuleType, but can be called manually after RegisterModuleType in order to
// override the factory method used for documentation, for example if the method passed to
// RegisterModuleType was a lambda.
func RegisterModuleTypeForDocs(name string, factory reflect.Value) {
	moduleTypesForDocs[name] = factory
}

func RegisterSingletonType(name string, factory SingletonFactory) {
	singletons = append(singletons, newSingleton(name, factory))
}

func RegisterPreSingletonType(name string, factory SingletonFactory) {
	preSingletons = append(preSingletons, newPreSingleton(name, factory))
}

type Context struct {
	*blueprint.Context
	config Config
}

func NewContext(config Config) *Context {
	ctx := &Context{blueprint.NewContext(), config}
	ctx.SetSrcDir(absSrcDir)
	return ctx
}

// RegisterForBazelConversion registers an alternate shadow pipeline of
// singletons, module types and mutators to register for converting Blueprint
// files to semantically equivalent BUILD files.
func (ctx *Context) RegisterForBazelConversion() {
	for _, t := range moduleTypes {
		t.register(ctx)
	}

	// Required for SingletonModule types, even though we are not using them.
	for _, t := range singletons {
		t.register(ctx)
	}

	bp2buildMutatorList := []RegisterMutatorFunc{}
	for t, f := range bp2buildMutators {
		ctx.config.bp2buildModuleTypeConfig[t] = true
		bp2buildMutatorList = append(bp2buildMutatorList, f)
	}

	RegisterMutatorsForBazelConversion(ctx, bp2buildPreArchMutators, bp2buildDepsMutators, bp2buildMutatorList)
}

// Register the pipeline of singletons, module types, and mutators for
// generating build.ninja and other files for Kati, from Android.bp files.
func (ctx *Context) Register() {
	preSingletons.registerAll(ctx)

	for _, t := range moduleTypes {
		t.register(ctx)
	}

	if ctx.config.BazelContext.BazelEnabled() {
		// Hydrate the configuration of bp2build-enabled module types. This is
		// required as a signal to identify which modules should be deferred to
		// Bazel in mixed builds, if it is enabled.
		for t, _ := range bp2buildMutators {
			ctx.config.bp2buildModuleTypeConfig[t] = true
		}
	}

	mutators := collateGloballyRegisteredMutators()
	mutators.registerAll(ctx)

	singletons := collateGloballyRegisteredSingletons()
	singletons.registerAll(ctx)
}

func collateGloballyRegisteredSingletons() sortableComponents {
	allSingletons := append(sortableComponents(nil), singletons...)
	allSingletons = append(allSingletons,
		singleton{false, "bazeldeps", BazelSingleton},

		// Register phony just before makevars so it can write out its phony rules as Make rules
		singleton{false, "phony", phonySingletonFactory},

		// Register makevars after other singletons so they can export values through makevars
		singleton{false, "makevars", makeVarsSingletonFunc},

		// Register env and ninjadeps last so that they can track all used environment variables and
		// Ninja file dependencies stored in the config.
		singleton{false, "ninjadeps", ninjaDepsSingletonFactory},
	)

	return allSingletons
}

func ModuleTypeFactories() map[string]ModuleFactory {
	ret := make(map[string]ModuleFactory)
	for _, t := range moduleTypes {
		ret[t.name] = t.factory
	}
	return ret
}

func ModuleTypeFactoriesForDocs() map[string]reflect.Value {
	return moduleTypesForDocs
}

// Interface for registering build components.
//
// Provided to allow registration of build components to be shared between the runtime
// and test environments.
type RegistrationContext interface {
	RegisterModuleType(name string, factory ModuleFactory)
	RegisterSingletonModuleType(name string, factory SingletonModuleFactory)
	RegisterPreSingletonType(name string, factory SingletonFactory)
	RegisterSingletonType(name string, factory SingletonFactory)
	PreArchMutators(f RegisterMutatorFunc)

	// Register pre arch mutators that are hard coded into mutator.go.
	//
	// Only registers mutators for testing, is a noop on the InitRegistrationContext.
	HardCodedPreArchMutators(f RegisterMutatorFunc)

	PreDepsMutators(f RegisterMutatorFunc)
	PostDepsMutators(f RegisterMutatorFunc)
	FinalDepsMutators(f RegisterMutatorFunc)
}

// Used to register build components from an init() method, e.g.
//
// init() {
//   RegisterBuildComponents(android.InitRegistrationContext)
// }
//
// func RegisterBuildComponents(ctx android.RegistrationContext) {
//   ctx.RegisterModuleType(...)
//   ...
// }
//
// Extracting the actual registration into a separate RegisterBuildComponents(ctx) function
// allows it to be used to initialize test context, e.g.
//
//   ctx := android.NewTestContext(config)
//   RegisterBuildComponents(ctx)
var InitRegistrationContext RegistrationContext = &initRegistrationContext{
	moduleTypes:       make(map[string]ModuleFactory),
	singletonTypes:    make(map[string]SingletonFactory),
	preSingletonTypes: make(map[string]SingletonFactory),
}

// Make sure the TestContext implements RegistrationContext.
var _ RegistrationContext = (*TestContext)(nil)

type initRegistrationContext struct {
	moduleTypes        map[string]ModuleFactory
	singletonTypes     map[string]SingletonFactory
	preSingletonTypes  map[string]SingletonFactory
	moduleTypesForDocs map[string]reflect.Value
}

func (ctx *initRegistrationContext) RegisterModuleType(name string, factory ModuleFactory) {
	if _, present := ctx.moduleTypes[name]; present {
		panic(fmt.Sprintf("module type %q is already registered", name))
	}
	ctx.moduleTypes[name] = factory
	RegisterModuleType(name, factory)
	RegisterModuleTypeForDocs(name, reflect.ValueOf(factory))
}

func (ctx *initRegistrationContext) RegisterSingletonModuleType(name string, factory SingletonModuleFactory) {
	s, m := SingletonModuleFactoryAdaptor(name, factory)
	ctx.RegisterSingletonType(name, s)
	ctx.RegisterModuleType(name, m)
	// Overwrite moduleTypesForDocs with the original factory instead of the lambda returned by
	// SingletonModuleFactoryAdaptor so that docs can find the module type documentation on the
	// factory method.
	RegisterModuleTypeForDocs(name, reflect.ValueOf(factory))
}

func (ctx *initRegistrationContext) RegisterSingletonType(name string, factory SingletonFactory) {
	if _, present := ctx.singletonTypes[name]; present {
		panic(fmt.Sprintf("singleton type %q is already registered", name))
	}
	ctx.singletonTypes[name] = factory
	RegisterSingletonType(name, factory)
}

func (ctx *initRegistrationContext) RegisterPreSingletonType(name string, factory SingletonFactory) {
	if _, present := ctx.preSingletonTypes[name]; present {
		panic(fmt.Sprintf("pre singleton type %q is already registered", name))
	}
	ctx.preSingletonTypes[name] = factory
	RegisterPreSingletonType(name, factory)
}

func (ctx *initRegistrationContext) PreArchMutators(f RegisterMutatorFunc) {
	PreArchMutators(f)
}

func (ctx *initRegistrationContext) HardCodedPreArchMutators(f RegisterMutatorFunc) {
	// Nothing to do as the mutators are hard code in preArch in mutator.go
}

func (ctx *initRegistrationContext) PreDepsMutators(f RegisterMutatorFunc) {
	PreDepsMutators(f)
}

func (ctx *initRegistrationContext) PostDepsMutators(f RegisterMutatorFunc) {
	PostDepsMutators(f)
}

func (ctx *initRegistrationContext) FinalDepsMutators(f RegisterMutatorFunc) {
	FinalDepsMutators(f)
}
