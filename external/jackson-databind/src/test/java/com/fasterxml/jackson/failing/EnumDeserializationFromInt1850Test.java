package com.fasterxml.jackson.failing;

import com.fasterxml.jackson.annotation.JsonValue;

import com.fasterxml.jackson.databind.*;

public class EnumDeserializationFromInt1850Test extends BaseMapTest
{
    enum Example1 {
        A(101);
        final int x;
        Example1(int x) { this.x = x; }
        @JsonValue
        public int code() { return x; }
    }

    enum Example2 {
        A(202);
        @JsonValue
        public final int x;
        Example2(int x) { this.x = x; }
    }

    public void testEnumFromInt1850() throws Exception
    {
        final ObjectMapper mapper = newJsonMapper();

        String json = mapper.writeValueAsString(Example1.A);
        Example1 e1 = mapper.readValue(json, Example1.class);
        assertEquals(Example1.A, e1);

        json = mapper.writeValueAsString(Example2.A);
        Example2 e2 = mapper.readValue(json, Example2.class);
        assertEquals(Example2.A, e2);
    }
}
