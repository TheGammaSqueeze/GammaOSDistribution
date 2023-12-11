/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.android.xsdc.cpp;

import com.android.xsdc.CodeWriter;
import com.android.xsdc.FileSystem;
import com.android.xsdc.XmlSchema;
import com.android.xsdc.XsdConstants;
import com.android.xsdc.tag.*;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

import javax.xml.namespace.QName;

public class CppCodeGenerator {
    public static final int GENERATE_ENUMS = 1 << 0;
    public static final int GENERATE_PARSER = 1 << 1;

    private XmlSchema xmlSchema;
    private String pkgName;
    private Map<String, CppSimpleType> cppSimpleTypeMap;
    private CodeWriter enumsCppFile;
    private CodeWriter enumsHeaderFile;
    private CodeWriter parserCppFile;
    private CodeWriter parserHeaderFile;
    private boolean hasAttr;
    private boolean writer;
    private int generators;
    private boolean booleanGetter;

    private static final String UNKNOWN_ENUM = "UNKNOWN";

    public CppCodeGenerator(XmlSchema xmlSchema, String pkgName, boolean writer, int generators,
            boolean booleanGetter) throws CppCodeGeneratorException {
        this.xmlSchema = xmlSchema;
        this.pkgName = pkgName;
        this.writer = writer;
        this.generators = generators;
        this.booleanGetter = booleanGetter;

        // class naming validation
        {
            Set<String> nameSet = new HashSet<>();
            nameSet.add("XmlParser");
            for (XsdType type : xmlSchema.getTypeMap().values()) {
                if ((type instanceof XsdComplexType) || (type instanceof XsdRestriction &&
                        ((XsdRestriction)type).getEnums() != null)) {
                    String name = Utils.toClassName(type.getName());
                    if (nameSet.contains(name)) {
                        throw new CppCodeGeneratorException(
                                String.format("duplicate class name : %s", name));
                    }
                    nameSet.add(name);
                    if (type instanceof XsdComplexType && !hasAttr) {
                        hasAttr = hasAttribute((XsdComplexType)type);
                    }
                }
            }
            for (XsdElement element : xmlSchema.getElementMap().values()) {
                XsdType type = element.getType();
                if (type.getRef() == null && type instanceof XsdComplexType) {
                    String name = Utils.toClassName(element.getName());
                    if (nameSet.contains(name)) {
                        throw new CppCodeGeneratorException(
                                String.format("duplicate class name : %s", name));
                    }
                    nameSet.add(name);
                    if (!hasAttr) {
                        hasAttr = hasAttribute((XsdComplexType)type);
                    }
                }
            }
        }

        cppSimpleTypeMap = new HashMap<>();
        for (XsdType type : xmlSchema.getTypeMap().values()) {
            if (type instanceof XsdSimpleType) {
                XsdType refType = new XsdType(null, new QName(type.getName()));
                parseSimpleType(refType, true);
            }
        }
    }

    public void print(FileSystem fs)
            throws CppCodeGeneratorException, IOException {
        // cpp file, header file init
        String fileNameStem = pkgName.replace('.', '_');
        String enumsCppFileName = fileNameStem + "_enums.cpp";
        String enumsHeaderFileName = fileNameStem + "_enums.h";
        String parserCppFileName = fileNameStem + ".cpp";
        String parserHeaderFileName = fileNameStem + ".h";
        if ((this.generators & GENERATE_ENUMS) == GENERATE_ENUMS) {
            enumsCppFile = new CodeWriter(fs.getPrintWriter(enumsCppFileName));
            enumsHeaderFile = new CodeWriter(fs.getPrintWriter("include/" + enumsHeaderFileName));
        } else {
            enumsCppFile = new CodeWriter();
            enumsHeaderFile = new CodeWriter();
        }
        if ((this.generators & GENERATE_PARSER) == GENERATE_PARSER) {
            parserCppFile = new CodeWriter(fs.getPrintWriter(parserCppFileName));
            parserHeaderFile = new CodeWriter(fs.getPrintWriter("include/" + parserHeaderFileName));
        } else {
            parserCppFile = new CodeWriter();
            parserHeaderFile = new CodeWriter();
        }

        boolean hasEnums = false;
        for (XsdType type : xmlSchema.getTypeMap().values()) {
            if (type instanceof XsdRestriction &&
                  ((XsdRestriction)type).getEnums() != null) {
                hasEnums = true;
                break;
            }
        }

        String enumsHeaderMacro = enumsHeaderFileName.toUpperCase().replace('.', '_');
        String parserHeaderMacro = parserHeaderFileName.toUpperCase().replace('.', '_');
        enumsHeaderFile.printf("#ifndef %s\n", enumsHeaderMacro);
        enumsHeaderFile.printf("#define %s\n", enumsHeaderMacro);
        enumsHeaderFile.printf("\n");
        enumsHeaderFile.printf("#include <array>\n");
        enumsHeaderFile.printf("#include <string>\n");
        enumsHeaderFile.printf("\n");
        parserHeaderFile.printf("#ifndef %s\n", parserHeaderMacro);
        parserHeaderFile.printf("#define %s\n", parserHeaderMacro);
        parserHeaderFile.printf("\n");
        parserHeaderFile.printf("#include <array>\n");
        parserHeaderFile.printf("#include <map>\n");
        parserHeaderFile.printf("#include <optional>\n");
        parserHeaderFile.printf("#include <string>\n");
        parserHeaderFile.printf("#include <vector>\n");
        if (writer) {
            parserHeaderFile.printf("#include <iostream>\n");
        }
        parserHeaderFile.printf("\n");
        parserHeaderFile.printf("#if __has_include(<libxml/parser.h>)\n");
        parserHeaderFile.printf("#include <libxml/parser.h>\n");
        parserHeaderFile.printf("#include <libxml/xinclude.h>\n");
        parserHeaderFile.printf("#else\n");
        parserHeaderFile.printf("#error Require libxml2 library. ");
        parserHeaderFile.printf("Please add libxml2 to shared_libs or static_libs\n");
        parserHeaderFile.printf("#endif\n");
        if (hasEnums) {
            enumsHeaderFile.printf("#include <xsdc/XsdcSupport.h>\n");
            enumsHeaderFile.printf("\n");
        }
        parserHeaderFile.printf("\n");
        parserHeaderFile.printf("#include \"%s\"\n", enumsHeaderFileName);
        parserHeaderFile.printf("\n");

        enumsCppFile.printf("#include <map>\n");
        enumsCppFile.printf("\n");
        enumsCppFile.printf("#include \"%s\"\n\n", enumsHeaderFileName);
        parserCppFile.printf("#define LOG_TAG \"%s\"\n", pkgName);
        parserCppFile.printf("#include \"%s\"\n\n", parserHeaderFileName);

        List<String> namespace = new java.util.ArrayList<>();
        for (String token : pkgName.split("\\.")) {
            if (token.isEmpty()) {
                continue;
            }
            if (Character.isDigit(token.charAt(0))) {
                token = "_" + token;
            }
            namespace.add(token);
            enumsHeaderFile.printf("namespace %s {\n", token);
            enumsCppFile.printf("namespace %s {\n", token);
            parserHeaderFile.printf("namespace %s {\n", token);
            parserCppFile.printf("namespace %s {\n", token);
        }

        printPrototype();
        printXmlParser();
        if (writer) {
            printXmlWriter();
        }

        for (XsdType type : xmlSchema.getTypeMap().values()) {
            if (type instanceof XsdRestriction &&
                  ((XsdRestriction)type).getEnums() != null) {
                String name = Utils.toClassName(type.getName());
                XsdRestriction restrictionType = (XsdRestriction) type;
                printEnum(name, restrictionType);
            }
        }
        for (XsdType type : xmlSchema.getTypeMap().values()) {
            if (type instanceof XsdComplexType) {
                String name = Utils.toClassName(type.getName());
                XsdComplexType complexType = (XsdComplexType) type;
                printClass(name, "", complexType);
            }
        }
        for (XsdElement element : xmlSchema.getElementMap().values()) {
            XsdType type = element.getType();
            if (type.getRef() == null && type instanceof XsdComplexType) {
                String name = Utils.toClassName(element.getName());
                XsdComplexType complexType = (XsdComplexType) type;
                printClass(name, "", complexType);
            }
        }

        Collections.reverse(namespace);
        for (String token : namespace) {
            enumsHeaderFile.printf("} // %s\n", token);
            enumsCppFile.printf("} // %s\n", token);
            parserHeaderFile.printf("} // %s\n", token);
            parserCppFile.printf("} // %s\n", token);
        }

        if (hasEnums) {
            enumsHeaderFile.printf("\n//\n// global type declarations for package\n//\n\n");
            enumsHeaderFile.printf("namespace android {\nnamespace details {\n");
            Collections.reverse(namespace);
            for (XsdType type : xmlSchema.getTypeMap().values()) {
                if (type instanceof XsdRestriction &&
                        ((XsdRestriction)type).getEnums() != null) {
                    String name = Utils.toClassName(type.getName());
                    XsdRestriction restrictionType = (XsdRestriction) type;
                    printEnumValues(namespace, name, restrictionType);
                }
            }
            enumsHeaderFile.printf("}  // namespace details\n}  // namespace android\n\n");
        }

        parserHeaderFile.printf("#endif // %s\n", parserHeaderMacro);
        enumsHeaderFile.printf("#endif // %s\n", enumsHeaderMacro);
        parserCppFile.close();
        parserHeaderFile.close();
        enumsCppFile.close();
        enumsHeaderFile.close();
    }

    private void printEnum(String name, XsdRestriction restrictionType)
            throws CppCodeGeneratorException {
        enumsHeaderFile.printf("enum class %s {\n", name);
        enumsCppFile.printf("const std::map<std::string, %s> %sString {\n", name, name);
        List<XsdEnumeration> enums = restrictionType.getEnums();

        enumsHeaderFile.printf("%s = %d,\n", UNKNOWN_ENUM, -1);
        for (XsdEnumeration tag : enums) {
            String value = tag.getValue();
            enumsHeaderFile.printf("%s,\n", Utils.toEnumName(value));
            enumsCppFile.printf("{ \"%s\", %s::%s },\n", tag.getValue(), name,
                    Utils.toEnumName(value));
        }
        enumsHeaderFile.printf("};\n");
        enumsCppFile.printf("};\n\n");

        enumsHeaderFile.printf("%s stringTo%s(const std::string& value);\n",
                name, name);
        enumsCppFile.printf("%s stringTo%s(const std::string& value) {\n"
                + "auto enumValue = %sString.find(value);\n"
                + "return enumValue != %sString.end() ? enumValue->second : %s::%s;\n"
                + "}\n\n", name, name, name, name, name, UNKNOWN_ENUM);

        enumsHeaderFile.printf("std::string toString(%s o);\n\n", name);
        enumsCppFile.printf("std::string toString(%s o) {\n", name);
        enumsCppFile.printf("switch (o) {\n");
        for (XsdEnumeration tag : enums) {
            String value = tag.getValue();
            enumsCppFile.printf("case %s::%s: return \"%s\";\n",
                    name, Utils.toEnumName(value), tag.getValue());
        }
        enumsCppFile.printf("default: return std::to_string(static_cast<int>(o));\n}\n");
        enumsCppFile.printf("}\n\n");
    }

    private void printEnumValues(List<String> namespace, String name,
            XsdRestriction restrictionType) throws CppCodeGeneratorException {
        List<XsdEnumeration> enums = restrictionType.getEnums();
        String absoluteNamespace = "::" + String.join("::", namespace);
        enumsHeaderFile.printf("template<> inline constexpr std::array<%s::%s, %d> "
                + "xsdc_enum_values<%s::%s> = {\n",
                absoluteNamespace, name, enums.size(), absoluteNamespace, name);
        for (XsdEnumeration tag : enums) {
            String value = tag.getValue();
            enumsHeaderFile.printf("%s::%s::%s,\n",
                    absoluteNamespace, name, Utils.toEnumName(value));
        }
        enumsHeaderFile.printf("};\n");
    }

    private void printPrototype() throws CppCodeGeneratorException {
        for (XsdType type : xmlSchema.getTypeMap().values()) {
            if (type instanceof XsdComplexType) {
                String name = Utils.toClassName(type.getName());
                parserHeaderFile.printf("class %s;\n", name);
            }
        }
        for (XsdElement element : xmlSchema.getElementMap().values()) {
            XsdType type = element.getType();
            if (type.getRef() == null && type instanceof XsdComplexType) {
                String name = Utils.toClassName(element.getName());
                parserHeaderFile.printf("class %s;\n", name);
            }
        }
    }

    private void printClass(String name, String nameScope, XsdComplexType complexType)
            throws CppCodeGeneratorException {
        assert name != null;
        // need element, attribute name duplicate validation?

        String baseName = getBaseName(complexType);
        CppSimpleType valueType = (complexType instanceof XsdSimpleContent) ?
                getValueType((XsdSimpleContent) complexType, false) : null;

        parserHeaderFile.printf("class %s ", name);

        if (baseName != null) {
            parserHeaderFile.printf(": public %s {\n", baseName);
        } else {
            parserHeaderFile.println("{");
        }

        // parse types for elements and attributes
        List<CppType> elementTypes = new ArrayList<>();
        List<XsdElement> elements = new ArrayList<>();
        elements.addAll(getAllElements(complexType.getGroup()));
        elements.addAll(complexType.getElements());

        for (XsdElement element : elements) {
            CppType cppType;
            XsdElement elementValue = resolveElement(element);
            if (element.getRef() == null && element.getType().getRef() == null
                    && element.getType() instanceof XsdComplexType) {
                // print inner class for anonymous types
                parserHeaderFile.printf("public:\n");
                String innerName = Utils.toClassName(getElementName(element));
                XsdComplexType innerType = (XsdComplexType) element.getType();
                printClass(innerName, nameScope + name + "::", innerType);
                parserHeaderFile.println();
                cppType = new CppComplexType(nameScope + name + "::"+ innerName);
            } else {
                cppType = parseType(elementValue.getType(), getElementName(elementValue));
            }
            elementTypes.add(cppType);
        }
        List<CppSimpleType> attributeTypes = new ArrayList<>();
        List<XsdAttribute> attributes = new ArrayList();
        for (XsdAttributeGroup attributeGroup : complexType.getAttributeGroups()) {
            attributes.addAll(getAllAttributes(resolveAttributeGroup(attributeGroup)));
        }
        attributes.addAll(complexType.getAttributes());

        for (XsdAttribute attribute : attributes) {
            XsdType type = resolveAttribute(attribute).getType();
            attributeTypes.add(parseSimpleType(type, false));
        }

        // print member variables

        parserHeaderFile.printf("private:\n");
        for (int i = 0; i < elementTypes.size(); ++i) {
            CppType type = elementTypes.get(i);
            XsdElement element = elements.get(i);
            XsdElement elementValue = resolveElement(element);
            String typeName = Utils.elementTypeName(type.getName(),
                    element.isMultiple() || type instanceof CppComplexType);
            parserHeaderFile.printf("const %s %s_;\n", typeName,
                    Utils.toVariableName(getElementName(elementValue)));
        }
        for (int i = 0; i < attributeTypes.size(); ++i) {
            CppType type = attributeTypes.get(i);
            XsdAttribute attribute = resolveAttribute(attributes.get(i));
            String variableName = Utils.toVariableName(attribute.getName());
            if (attribute.isRequired()) {
                parserHeaderFile.printf("const %s %s_;\n", type.getName(), variableName);
            } else {
                parserHeaderFile.printf("const std::optional<%s> %s_;\n",
                        type.getName(), variableName);
            }
        }
        if (valueType != null) {
            parserHeaderFile.printf("const std::optional<%s> _value;\n", valueType.getName());
        }

        parserHeaderFile.printf("public:\n");
        String constructorArgs = printConstructor(name, nameScope, complexType, elements,
                attributes, baseName);

        // print getters and setters
        for (int i = 0; i < elementTypes.size(); ++i) {
            CppType type = elementTypes.get(i);
            XsdElement element = elements.get(i);
            XsdElement elementValue = resolveElement(element);
            printGetter(nameScope + name, type,
                    Utils.toVariableName(getElementName(elementValue)),
                    type instanceof CppComplexType ? true : element.isMultiple(),
                    type instanceof CppComplexType ? false : ((CppSimpleType)type).isList(),
                    false);
        }
        for (int i = 0; i < attributeTypes.size(); ++i) {
            CppType type = attributeTypes.get(i);
            XsdAttribute attribute = resolveAttribute(attributes.get(i));
            printGetter(nameScope + name, type, Utils.toVariableName(attribute.getName()),
                    false, false, attribute.isRequired());
        }
        if (valueType != null) {
            printGetter(nameScope + name, valueType, "value", false, false, false);
        }

        printParser(name, nameScope, complexType, constructorArgs);

        if (writer) {
            printWriter(name, nameScope, complexType);
        }

        parserHeaderFile.println("};\n");
    }

    private void printParser(String name, String nameScope, XsdComplexType complexType, String args)
            throws CppCodeGeneratorException {
        CppSimpleType baseValueType = (complexType instanceof XsdSimpleContent) ?
                getValueType((XsdSimpleContent) complexType, true) : null;
        List<XsdElement> allElements = new ArrayList<>();
        List<XsdAttribute> allAttributes = new ArrayList<>();
        stackComponents(complexType, allElements, allAttributes);

        // parse types for elements and attributes
        List<CppType> allElementTypes = new ArrayList<>();
        for (XsdElement element : allElements) {
            XsdElement elementValue = resolveElement(element);
            CppType cppType = parseType(elementValue.getType(), elementValue.getName());
            allElementTypes.add(cppType);
        }
        List<CppSimpleType> allAttributeTypes = new ArrayList<>();
        for (XsdAttribute attribute : allAttributes) {
            XsdType type = resolveAttribute(attribute).getType();
            allAttributeTypes.add(parseSimpleType(type, false));
        }

        String fullName = nameScope + name;
        parserHeaderFile.printf("static %s read(xmlNode *root);\n", fullName, Utils.lowerize(name));
        parserCppFile.printf("\n%s %s::read(xmlNode *root) {\n", fullName, fullName);

        parserCppFile.print("std::string raw;\n");

        for (int i = 0; i < allAttributes.size(); ++i) {
            CppSimpleType type = allAttributeTypes.get(i);
            XsdAttribute attribute = resolveAttribute(allAttributes.get(i));
            String variableName = Utils.toVariableName(attribute.getName());
            parserCppFile.printf("raw = getXmlAttribute(root, \"%s\");\n", attribute.getName());
            if (attribute.isRequired()) {
                if (type.isEnum()) {
                    parserCppFile.printf("%s %s = %s::%s;\n",
                            type.getName(), variableName, type.getName(), UNKNOWN_ENUM);
                } else {
                    parserCppFile.printf("%s %s{};\n", type.getName(), variableName);
                }
            } else {
                parserCppFile.printf("std::optional<%s> %s = std::nullopt;\n", type.getName(),
                        variableName);
            }
            parserCppFile.printf("if (raw != \"\") {\n");
            parserCppFile.print(type.getParsingExpression());
            parserCppFile.printf("%s = value;\n}\n", variableName);
        }

        if (baseValueType != null) {
            parserCppFile.printf("auto xmlValue = make_xmlUnique(xmlNodeListGetString("
                    + "root->doc, root->xmlChildrenNode, 1));\n"
                    + "if (xmlValue != nullptr) {\n"
                    + "raw = reinterpret_cast<const char*>(xmlValue.get());\n");

            parserCppFile.print(baseValueType.getParsingExpression());
            parserCppFile.printf("instance.setValue(value);\n");
            parserCppFile.printf("}\n");
        } else if (!allElements.isEmpty()) {
            for (int i = 0; i < allElements.size(); ++i) {
                CppType type = allElementTypes.get(i);
                XsdElement element = allElements.get(i);
                XsdElement elementValue = resolveElement(element);
                String variableName = Utils.toVariableName(getElementName(elementValue));
                parserCppFile.printf("%s %s;\n", Utils.elementTypeName(type.getName(),
                        element.isMultiple() || type instanceof CppComplexType), variableName);
            }
            parserCppFile.print("for (xmlNode *child = root->xmlChildrenNode; child != nullptr;"
                    + " child = child->next) {\n");
            for (int i = 0; i < allElements.size(); ++i) {
                CppType type = allElementTypes.get(i);
                XsdElement element = allElements.get(i);
                XsdElement elementValue = resolveElement(element);
                String variableName = Utils.toVariableName(getElementName(elementValue));

                if (i != 0) parserCppFile.printf("} else ");
                parserCppFile.print("if (!xmlStrcmp(child->name, reinterpret_cast<const xmlChar*>");
                parserCppFile.printf("(\"%s\"))) {\n", elementValue.getName());

                if (type instanceof CppSimpleType) {
                    parserCppFile.print("auto xmlValue = make_xmlUnique(xmlNodeListGetString(");
                    parserCppFile.print("child->doc, child->xmlChildrenNode, 1));\n");
                    parserCppFile.print("if (xmlValue == nullptr) {\nraw = \"\";\n} else {\n");
                    parserCppFile.print("raw = reinterpret_cast<const char*>(xmlValue.get());\n}");
                    parserCppFile.print("\n");
                }

                parserCppFile.print(type.getParsingExpression());

                if (element.isMultiple() || type instanceof CppComplexType) {
                    parserCppFile.printf("%s.push_back(std::move(value));\n", variableName);
                } else {
                    parserCppFile.printf("%s = std::move(value);\n", variableName);
                }
            }
            parserCppFile.printf("}\n}\n");
        }
        parserCppFile.printf("%s instance%s;\n",
                fullName, args.length() > 0 ? "(" + args + ")" : "");
        parserCppFile.print("return instance;\n}\n");
    }

    private void printWriter(String name, String nameScope, XsdComplexType complexType)
            throws CppCodeGeneratorException {
        CppSimpleType baseValueType = (complexType instanceof XsdSimpleContent) ?
                getValueType((XsdSimpleContent) complexType, true) : null;
        List<XsdElement> allElements = new ArrayList<>();
        List<XsdAttribute> allAttributes = new ArrayList<>();
        stackComponents(complexType, allElements, allAttributes);

        // parse types for elements and attributes
        List<CppType> allElementTypes = new ArrayList<>();
        for (XsdElement element : allElements) {
            XsdElement elementValue = resolveElement(element);
            CppType cppType = parseType(elementValue.getType(), elementValue.getName());
            allElementTypes.add(cppType);
        }
        List<CppSimpleType> allAttributeTypes = new ArrayList<>();
        for (XsdAttribute attribute : allAttributes) {
            XsdType type = resolveAttribute(attribute).getType();
            allAttributeTypes.add(parseSimpleType(type, false));
        }

        String fullName = nameScope + name;
        parserHeaderFile.printf("void write(std::ostream& out, const std::string& name) const;\n");
        parserCppFile.printf(
                "\nvoid %s::write(std::ostream& out, const std::string& name) const {\n",
                fullName);

        parserCppFile.printf("out << printIndent() << \"<\" << name;\n");
        for (int i = 0; i < allAttributes.size(); ++i) {
            CppType type = allAttributeTypes.get(i);
            XsdAttribute attribute = resolveAttribute(allAttributes.get(i));
            String variableName = Utils.toVariableName(attribute.getName());
            parserCppFile.printf("if (has%s()) {\n", Utils.capitalize(variableName));
            parserCppFile.printf("out << \" %s=\\\"\";\n", attribute.getName());
            parserCppFile.print(type.getWritingExpression(String.format("%s%s()",
                    getterName(type.getName()), Utils.capitalize(variableName)),
                    attribute.getName()));
            parserCppFile.printf("out << \"\\\"\";\n}\n");
        }
        parserCppFile.print("out << \">\" << std::endl;\n");
        parserCppFile.print("++indentIndex;\n");

        if (!allElements.isEmpty()) {
            for (int i = 0; i < allElements.size(); ++i) {
                CppType type = allElementTypes.get(i);
                XsdElement element = allElements.get(i);
                XsdElement elementValue = resolveElement(element);
                String elementName = getElementName(elementValue);
                String variableName = Utils.toVariableName(elementName);

                if (type instanceof CppComplexType || element.isMultiple()) {
                    parserCppFile.printf("for (auto& value : get%s()) {\n",
                            Utils.capitalize(variableName));
                    if (type instanceof CppSimpleType) {
                        parserCppFile.printf("out << printIndent() << \"<%s>\";\n",
                                elementValue.getName());
                    }
                    parserCppFile.printf(
                            type.getWritingExpression("value", elementValue.getName()));
                    if (type instanceof CppSimpleType) {
                        parserCppFile.printf("out << \"</%s>\" << std::endl;\n",
                                elementValue.getName());
                    }
                    parserCppFile.printf("}\n");
                } else {
                    parserCppFile.printf("if (has%s()) {\n", Utils.capitalize(variableName));
                    if (type instanceof CppSimpleType) {
                        parserCppFile.printf("out << printIndent() << \"<%s>\";\n",
                                elementValue.getName());
                    }
                    parserCppFile.print(type.getWritingExpression(String.format("%s%s()",
                              getterName(type.getName()), Utils.capitalize(variableName)),
                              elementValue.getName()));
                    if (type instanceof CppSimpleType) {
                        parserCppFile.printf("out << \"</%s>\" << std::endl;\n",
                                elementValue.getName());
                    }
                    parserCppFile.print("}\n");
                }
            }
        }
        parserCppFile.print("--indentIndex;\n");
        parserCppFile.printf("out << printIndent() << \"</\" << name << \">\" << std::endl;\n");
        parserCppFile.printf("}\n");
    }

    private void printGetter(String name, CppType type, String variableName,
            boolean isMultiple, boolean isMultipleType, boolean isRequired) {
        String typeName = isMultiple ? String.format("std::vector<%s>",
                type.getName()) : type.getName();

        parserHeaderFile.printf("const %s& %s%s() const;\n", typeName, getterName(typeName),
                Utils.capitalize(variableName));

        parserCppFile.println();
        parserCppFile.printf("const %s& %s::%s%s() const {\n"
                + "return %s;\n}\n\n",
                typeName, name, getterName(typeName), Utils.capitalize(variableName),
                isMultiple || isRequired ?
                variableName + "_" : String.format("%s_.value()", variableName));

        parserHeaderFile.printf("bool has%s() const;\n", Utils.capitalize(variableName));
        parserCppFile.printf("bool %s::has%s() const {\n", name, Utils.capitalize(variableName));
        if (isMultiple) {
            parserCppFile.printf("return !(%s_.empty());\n}\n", variableName);
        } else if (isRequired){
            parserCppFile.print("return true;\n}\n");
        } else {
            parserCppFile.printf("return %s_.has_value();\n}\n", variableName);
        }

        if (isMultiple || isMultipleType) {
            String elementTypeName = type instanceof CppComplexType ? type.getName() :
                    ((CppSimpleType)type).getTypeName();
            if (elementTypeName.equals("bool")) {
                parserHeaderFile.printf("%s getFirst%s() const;\n",
                        elementTypeName, Utils.capitalize(variableName));
                parserCppFile.println();
                parserCppFile.printf("%s %s::getFirst%s() const {\n"
                        + "if (%s_%sempty()) {\n"
                        + "return false;\n"
                        + "}\n"
                        + "return %s;\n"
                        + "}\n",
                        elementTypeName, name, Utils.capitalize(variableName), variableName,
                        isMultiple ? "." : "->",
                        isMultiple ? String.format("%s_[0]", variableName) :
                        String.format("%s_.value()[0]", variableName));
            } else {
                parserHeaderFile.printf("const %s* getFirst%s() const;\n",
                        elementTypeName, Utils.capitalize(variableName));
                parserCppFile.println();
                parserCppFile.printf("const %s* %s::getFirst%s() const {\n"
                        + "if (%s_%sempty()) {\n"
                        + "return nullptr;\n"
                        + "}\n"
                        + "return &%s;\n"
                        + "}\n",
                        elementTypeName, name, Utils.capitalize(variableName), variableName,
                        isMultiple ? "." : "->",
                        isMultiple ? String.format("%s_[0]", variableName) :
                        String.format("%s_.value()[0]", variableName));
            }
        }
    }

    private String printConstructor(String name, String nameScope, XsdComplexType complexType,
            List<XsdElement> elements, List<XsdAttribute> attributes, String baseName)
            throws CppCodeGeneratorException {
        String fullName = nameScope + name;
        StringBuilder constructorArgs = new StringBuilder();
        StringBuilder parentArgs = new StringBuilder();
        StringBuilder constructor = new StringBuilder();
        StringBuilder args = new StringBuilder();

        List<XsdElement> allElements = new ArrayList<>();
        List<XsdAttribute> allAttributes = new ArrayList<>();
        stackComponents(complexType, allElements, allAttributes);

        List<CppType> allElementTypes = new ArrayList<>();
        for (XsdElement element : allElements) {
            XsdElement elementValue = resolveElement(element);
            CppType type = parseType(elementValue.getType(), elementValue.getName());
            String variableName = Utils.toVariableName(getElementName(elementValue));
            constructorArgs.append(String.format(", %s %s", Utils.elementTypeName(type.getName(),
                    element.isMultiple() || type instanceof CppComplexType), variableName));
            args.append(String.format(", %s", variableName));
            boolean isMultipleType;
            if (type instanceof CppComplexType) {
                isMultipleType = true;
            } else if (((CppSimpleType)type).isList()) {
                isMultipleType = true;
            } else {
                isMultipleType = false;
            }

            if (elements.contains(element)) {
                constructor.append(String.format(", %s_(%s)", variableName,
                        Utils.toAssignmentName(type.getName(), variableName, isMultipleType)));
            } else {
                parentArgs.append(String.format(", %s", variableName));
            }
        }
        List<CppSimpleType> allAttributeTypes = new ArrayList<>();
        for (XsdAttribute attribute : allAttributes) {
            CppType type = parseSimpleType(resolveAttribute(attribute).getType(), false);
            String variableName = Utils.toVariableName(resolveAttribute(attribute).getName());
            if (attribute.isRequired()) {
                constructorArgs.append(String.format(", %s %s", type.getName(), variableName));
            } else {
                constructorArgs.append(String.format(", std::optional<%s> %s", type.getName(),
                        variableName));
            }
            args.append(String.format(", %s", variableName));
            boolean isMultipleType = ((CppSimpleType)type).isList() ? true : false;
            if (attributes.contains(attribute)) {
                constructor.append(String.format(", %s_(%s)", variableName,
                        Utils.toAssignmentName(type.getName(), variableName, isMultipleType)));
            } else {
                parentArgs.append(String.format(", %s", variableName));
            }
        }

        String constructorArgsString = constructorArgs.toString();
        String constructorString = constructor.toString();
        if (constructorArgsString.length() > 0) {
            constructorArgsString = constructorArgsString.substring(2);
        }

        boolean useExplicit =
                !(constructorArgsString.isEmpty() || constructorArgsString.contains(","));
        if (useExplicit) {
            parserHeaderFile.printf("explicit %s(%s);\n", name, constructorArgsString);
        } else {
            parserHeaderFile.printf("%s(%s);\n", name, constructorArgsString);
        }
        parserCppFile.printf("\n%s::%s(%s) : ", fullName, name, constructorArgsString);

        String parentArgsString = parentArgs.toString();
        if (parentArgsString.length() > 0) {
            parentArgsString = parentArgsString.substring(2);
            parserCppFile.printf("%s(%s)", baseName, parentArgsString);
        } else {
            constructorString = constructorString.substring(2);
        }
        parserCppFile.printf("%s {\n}\n", constructorString);

        String argsString = args.toString();
        if (argsString.length() > 0) {
            argsString = argsString.substring(2);
        }
        return argsString;
    }

    private void printXmlParser() throws CppCodeGeneratorException {
        parserCppFile.printf("template <class T>\n"
                + "constexpr void (*xmlDeleter)(T* t);\n"
                + "template <>\nconstexpr auto xmlDeleter<xmlDoc> = xmlFreeDoc;\n"
                + "template <>\nauto xmlDeleter<xmlChar> = [](xmlChar *s) { xmlFree(s); };\n\n"
                + "template <class T>\n"
                + "constexpr auto make_xmlUnique(T *t) {\n"
                + "auto deleter = [](T *t) { xmlDeleter<T>(t); };\n"
                + "return std::unique_ptr<T, decltype(deleter)>{t, deleter};\n"
                + "}\n\n");

        if (hasAttr) {
            parserCppFile.printf("static std::string getXmlAttribute"
                    + "(const xmlNode *cur, const char *attribute) {\n"
                    + "auto xmlValue = make_xmlUnique(xmlGetProp(cur, "
                    + "reinterpret_cast<const xmlChar*>(attribute)));\n"
                    + "if (xmlValue == nullptr) {\n"
                    + "return \"\";\n"
                    + "}\n"
                    + "std::string value(reinterpret_cast<const char*>(xmlValue.get()));\n"
                    + "return value;\n"
                    + "}\n\n");
        }

        String className = Utils.toClassName(pkgName);

        boolean isMultiRootElement = xmlSchema.getElementMap().values().size() > 1;
        for (XsdElement element : xmlSchema.getElementMap().values()) {
            CppType cppType = parseType(element.getType(), element.getName());
            String elementName = element.getName();
            String VariableName = Utils.toVariableName(elementName);
            String typeName = cppType instanceof CppSimpleType ? cppType.getName() :
                    Utils.toClassName(cppType.getName());

            parserHeaderFile.printf("std::optional<%s> read%s(const char* configFile);\n\n",
                    typeName, isMultiRootElement ? Utils.capitalize(typeName) : "");
            parserCppFile.printf("std::optional<%s> read%s(const char* configFile) {\n",
                    typeName, isMultiRootElement ? Utils.capitalize(typeName) : "");
            parserCppFile.printf("auto doc = make_xmlUnique(xmlParseFile(configFile));\n"
                    + "if (doc == nullptr) {\n"
                    + "return std::nullopt;\n"
                    + "}\n"
                    + "xmlNodePtr child = xmlDocGetRootElement(doc.get());\n"
                    + "if (child == nullptr) {\n"
                    + "return std::nullopt;\n"
                    + "}\n"
                    + "if (xmlXIncludeProcess(doc.get()) < 0) {\n"
                    + "return std::nullopt;\n"
                    + "}\n\n"
                    + "if (!xmlStrcmp(child->name, reinterpret_cast<const xmlChar*>"
                    + "(\"%s\"))) {\n",
                    elementName);

            if (cppType instanceof CppSimpleType) {
                parserCppFile.printf("%s value = getXmlAttribute(child, \"%s\");\n",
                        elementName, elementName);
            } else {
                parserCppFile.printf(cppType.getParsingExpression());
            }
            parserCppFile.printf("return value;\n}\n");
            parserCppFile.printf("return std::nullopt;\n");
            parserCppFile.printf("}\n\n");
        }
    }

    private void printXmlWriter() throws CppCodeGeneratorException {
        for (XsdElement element : xmlSchema.getElementMap().values()) {
            CppType cppType = parseType(element.getType(), element.getName());
            String elementName = element.getName();
            String VariableName = Utils.toVariableName(elementName);
            String typeName = cppType instanceof CppSimpleType ? cppType.getName() :
                    Utils.toClassName(cppType.getName());
            parserHeaderFile.printf("void write(std::ostream& out, %s& %s);\n\n",
                    typeName, VariableName);
            parserCppFile.printf("void write(std::ostream& out, %s& %s) {\n",
                    typeName, VariableName);

            parserCppFile.print(
                    "out << \"<?xml version=\\\"1.0\\\" encoding=\\\"utf-8\\\"?>\\n\";\n");
            parserCppFile.printf("%s.write(out, \"%s\");\n", VariableName, elementName);
            parserCppFile.printf("}\n\n");
        }

        parserCppFile.print("static int indentIndex = 0;\n"
                + "std::string printIndent() {\n"
                + "std::string s = \"\";\n"
                + "for (int index = 0; index < indentIndex; ++index) {\n"
                + "s += \"    \";\n"
                + "}\nreturn s;\n}\n\n");
    }

    private String getElementName(XsdElement element) {
        if (element instanceof XsdChoice) {
            return element.getName() + "_optional";
        } else if (element instanceof XsdAll) {
            return element.getName() + "_all";
        }
        return element.getName();
    }

    private String getterName(String type) {
        if (type.equals("bool") && booleanGetter) {
            return "is";
        }
        return "get";
    }

    private void stackComponents(XsdComplexType complexType, List<XsdElement> elements,
            List<XsdAttribute> attributes) throws CppCodeGeneratorException {
        if (complexType.getBase() != null) {
            QName baseRef = complexType.getBase().getRef();
            if (baseRef != null && !baseRef.getNamespaceURI().equals(XsdConstants.XSD_NAMESPACE)) {
                XsdType parent = getType(baseRef.getLocalPart());
                if (parent instanceof XsdComplexType) {
                    stackComponents((XsdComplexType) parent, elements, attributes);
                }
            }
        }
        elements.addAll(getAllElements(complexType.getGroup()));
        elements.addAll(complexType.getElements());
        for (XsdAttributeGroup attributeGroup : complexType.getAttributeGroups()) {
            attributes.addAll(getAllAttributes(resolveAttributeGroup(attributeGroup)));
        }
        attributes.addAll(complexType.getAttributes());
    }

    private List<XsdAttribute> getAllAttributes(XsdAttributeGroup attributeGroup)
            throws CppCodeGeneratorException{
        List<XsdAttribute> attributes = new ArrayList<>();
        for (XsdAttributeGroup attrGroup : attributeGroup.getAttributeGroups()) {
            attributes.addAll(getAllAttributes(resolveAttributeGroup(attrGroup)));
        }
        attributes.addAll(attributeGroup.getAttributes());
        return attributes;
    }

    private List<XsdElement> getAllElements(XsdGroup group) throws CppCodeGeneratorException {
        List<XsdElement> elements = new ArrayList<>();
        if (group == null) {
            return elements;
        }
        elements.addAll(getAllElements(resolveGroup(group)));
        elements.addAll(group.getElements());
        return elements;
    }


    private String getBaseName(XsdComplexType complexType) throws CppCodeGeneratorException {
        if (complexType.getBase() == null) return null;
        if (complexType.getBase().getRef().getNamespaceURI().equals(XsdConstants.XSD_NAMESPACE)) {
            return null;
        }
        XsdType base = getType(complexType.getBase().getRef().getLocalPart());
        if (base instanceof XsdComplexType) {
            return Utils.toClassName(base.getName());
        }
        return null;
    }

    private CppSimpleType getValueType(XsdSimpleContent simpleContent, boolean traverse)
            throws CppCodeGeneratorException {
        assert simpleContent.getBase() != null;
        QName baseRef = simpleContent.getBase().getRef();
        assert baseRef != null;
        if (baseRef.getNamespaceURI().equals(XsdConstants.XSD_NAMESPACE)) {
            return predefinedType(baseRef.getLocalPart());
        } else {
            XsdType parent = getType(baseRef.getLocalPart());
            if (parent instanceof XsdSimpleType) {
                return parseSimpleTypeReference(baseRef, false);
            }
            if (!traverse) return null;
            if (parent instanceof XsdSimpleContent) {
                return getValueType((XsdSimpleContent) parent, true);
            } else {
                throw new CppCodeGeneratorException(
                        String.format("base not simple : %s", baseRef.getLocalPart()));
            }
        }
    }

    private CppType parseType(XsdType type, String defaultName) throws CppCodeGeneratorException {
        if (type.getRef() != null) {
            String name = type.getRef().getLocalPart();
            if (type.getRef().getNamespaceURI().equals(XsdConstants.XSD_NAMESPACE)) {
                return predefinedType(name);
            } else {
                XsdType typeValue = getType(name);
                if (typeValue instanceof XsdSimpleType) {
                    return parseSimpleTypeReference(type.getRef(), false);
                }
                return parseType(typeValue, name);
            }
        }
        if (type instanceof XsdComplexType) {
            return new CppComplexType(Utils.toClassName(defaultName));
        } else if (type instanceof XsdSimpleType) {
            return parseSimpleTypeValue((XsdSimpleType) type, false);
        } else {
            throw new CppCodeGeneratorException(
                    String.format("unknown type name : %s", defaultName));
        }
    }

    private CppSimpleType parseSimpleType(XsdType type, boolean traverse)
            throws CppCodeGeneratorException {
        if (type.getRef() != null) {
            return parseSimpleTypeReference(type.getRef(), traverse);
        } else {
            return parseSimpleTypeValue((XsdSimpleType) type, traverse);
        }
    }

    private CppSimpleType parseSimpleTypeReference(QName typeRef, boolean traverse)
            throws CppCodeGeneratorException {
        assert typeRef != null;
        String typeName = typeRef.getLocalPart();
        if (typeRef.getNamespaceURI().equals(XsdConstants.XSD_NAMESPACE)) {
            return predefinedType(typeName);
        }
        if (cppSimpleTypeMap.containsKey(typeName)) {
            return cppSimpleTypeMap.get(typeName);
        } else if (traverse) {
            XsdSimpleType simpleType = getSimpleType(typeName);
            CppSimpleType ret = parseSimpleTypeValue(simpleType, true);
            cppSimpleTypeMap.put(typeName, ret);
            return ret;
        } else {
            throw new CppCodeGeneratorException(String.format("unknown type name : %s", typeName));
        }
    }

    private CppSimpleType parseSimpleTypeValue(XsdSimpleType simpleType, boolean traverse)
            throws CppCodeGeneratorException {
        if (simpleType instanceof XsdList) {
            XsdList list = (XsdList) simpleType;
            return parseSimpleType(list.getItemType(), traverse).newListType();
        } else if (simpleType instanceof XsdRestriction) {
            // we don't consider any restrictions.
            XsdRestriction restriction = (XsdRestriction) simpleType;
            if (restriction.getEnums() != null) {
                String name = Utils.toClassName(restriction.getName());
                return new CppSimpleType(name, "stringTo" + name + "(%s)", false, true);
            }
            return parseSimpleType(restriction.getBase(), traverse);
        } else if (simpleType instanceof XsdUnion) {
            // unions are almost always interpreted as java.lang.String
            // Exceptionally, if any of member types of union are 'list', then we interpret it as
            // List<String>
            XsdUnion union = (XsdUnion) simpleType;
            for (XsdType memberType : union.getMemberTypes()) {
                if (parseSimpleType(memberType, traverse).isList()) {
                    return new CppSimpleType("std::string", "%s", true);
                }
            }
            return new CppSimpleType("std::string", "%s", false);
        } else {
            // unreachable
            throw new IllegalStateException("unknown simple type");
        }
    }

    private XsdElement resolveElement(XsdElement element) throws CppCodeGeneratorException {
        if (element.getRef() == null) return element;
        String name = element.getRef().getLocalPart();
        XsdElement ret = xmlSchema.getElementMap().get(name);
        if (ret != null) return ret;
        throw new CppCodeGeneratorException(String.format("no element named : %s", name));
    }

    private XsdGroup resolveGroup(XsdGroup group) throws CppCodeGeneratorException {
        if (group.getRef() == null) return null;
        String name = group.getRef().getLocalPart();
        XsdGroup ret = xmlSchema.getGroupMap().get(name);
        if (ret != null) return ret;
        throw new CppCodeGeneratorException(String.format("no group named : %s", name));
    }

    private XsdAttribute resolveAttribute(XsdAttribute attribute)
            throws CppCodeGeneratorException {
        if (attribute.getRef() == null) return attribute;
        String name = attribute.getRef().getLocalPart();
        XsdAttribute ret = xmlSchema.getAttributeMap().get(name);
        if (ret != null) return ret;
        throw new CppCodeGeneratorException(String.format("no attribute named : %s", name));
    }

    private XsdAttributeGroup resolveAttributeGroup(XsdAttributeGroup attributeGroup)
            throws CppCodeGeneratorException {
        if (attributeGroup.getRef() == null) return attributeGroup;
        String name = attributeGroup.getRef().getLocalPart();
        XsdAttributeGroup ret = xmlSchema.getAttributeGroupMap().get(name);
        if (ret != null) return ret;
        throw new CppCodeGeneratorException(String.format("no attribute group named : %s", name));
    }

    private XsdType getType(String name) throws CppCodeGeneratorException {
        XsdType type = xmlSchema.getTypeMap().get(name);
        if (type != null) return type;
        throw new CppCodeGeneratorException(String.format("no type named : %s", name));
    }

    private XsdSimpleType getSimpleType(String name) throws CppCodeGeneratorException {
        XsdType type = getType(name);
        if (type instanceof XsdSimpleType) return (XsdSimpleType) type;
        throw new CppCodeGeneratorException(String.format("not a simple type : %s", name));
    }

    private boolean hasAttribute(XsdComplexType complexType) throws CppCodeGeneratorException {
        if (complexType.getAttributes().size() > 0 ||
                complexType.getAttributeGroups().size() > 0) {
            return true;
        }
        boolean results = false;
        for (XsdElement element : complexType.getElements()) {
            XsdElement elementValue = resolveElement(element);
            if (element.getRef() == null && element.getType().getRef() == null
                    && element.getType() instanceof XsdComplexType) {
                results = hasAttribute((XsdComplexType) element.getType());
                if (results) {
                    return results;
                }
            }
        }
        return results;
    }

    private static CppSimpleType predefinedType(String name) throws CppCodeGeneratorException {
        switch (name) {
            case "string":
            case "token":
            case "normalizedString":
            case "language":
            case "ENTITY":
            case "ID":
            case "Name":
            case "NCName":
            case "NMTOKEN":
            case "anyURI":
            case "anyType":
            case "QName":
            case "NOTATION":
            case "IDREF":
                return new CppSimpleType("std::string", "%s", false);
            case "ENTITIES":
            case "NMTOKENS":
            case "IDREFS":
                return new CppSimpleType("std::string", "%s", true);
            case "date":
            case "dateTime":
            case "time":
            case "gDay":
            case "gMonth":
            case "gYear":
            case "gMonthDay":
            case "gYearMonth":
            case "duration":
                return new CppSimpleType("std::string", "%s", false);
            case "decimal":
                return new CppSimpleType("double", "std::stod(%s)", false);
            case "integer":
            case "negativeInteger":
            case "nonNegativeInteger":
            case "positiveInteger":
            case "nonPositiveInteger":
                return new CppSimpleType("int64_t", "std::stoll(%s)", false);
            case "unsignedLong":
                return new CppSimpleType("uint64_t", "std::stoull(%s)", false);
            case "long":
                return new CppSimpleType("int64_t", "std::stoll(%s)", false);
            case "unsignedInt":
                return new CppSimpleType("unsigned int",
                        "static_cast<unsigned int>(stoul(%s))", false);
            case "int":
                return new CppSimpleType("int", "std::stoi(%s)", false);
            case "unsignedShort":
                return new CppSimpleType("unsigned short",
                        "static_cast<unsigned short>(std::stoi(%s))", false);
            case "short":
                return new CppSimpleType("short", "static_cast<short>(std::stoi(%s))", false);
            case "unsignedByte":
                return new CppSimpleType("unsigned char",
                        "static_cast<unsigned char>(std::stoi(%s))", false);
            case "byte":
                return new CppSimpleType("char", "static_cast<char>(std::stoi(%s))", false);
            case "boolean":
                return new CppSimpleType("bool", "%s == \"true\"", false);
            case "double":
                return new CppSimpleType("double", "std::stod(%s)", false);
            case "float":
                return new CppSimpleType("float", "std::stof(%s)", false);
            case "base64Binary":
            case "hexBinary":
                return new CppSimpleType("std::string", "%s", false);
        }
        throw new CppCodeGeneratorException("unknown xsd predefined type : " + name);
    }
}
