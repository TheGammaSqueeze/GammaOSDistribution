/*
 * Copyright (C) 2021 The Android Open Source Project
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

package com.android.car.telemetry.publisher.statsconverters;

import static com.android.car.telemetry.AtomsProto.ANROccurred.ERROR_SOURCE_FIELD_NUMBER;
import static com.android.car.telemetry.AtomsProto.ANROccurred.PACKAGE_NAME_FIELD_NUMBER;
import static com.android.car.telemetry.AtomsProto.ANROccurred.REASON_FIELD_NUMBER;
import static com.android.car.telemetry.AtomsProto.ANROccurred.UID_FIELD_NUMBER;

import static com.google.common.truth.Truth.assertThat;

import static org.junit.Assert.assertThrows;

import android.os.PersistableBundle;
import android.util.SparseArray;

import com.android.car.telemetry.AtomsProto;
import com.android.car.telemetry.AtomsProto.ANROccurred;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import java.util.Arrays;
import java.util.List;

@RunWith(JUnit4.class)
public class AnrOccurredConverterTest {
    private static final String PACKAGE_NAME_1 = "com.example.package1";
    private static final String PACKAGE_NAME_2 = "com.example.package2";
    private static final AtomsProto.Atom ATOM_A =
            AtomsProto.Atom.newBuilder()
                    .setAnrOccurred(ANROccurred.newBuilder()
                            .setUid(1000)
                            .setPackageName(PACKAGE_NAME_1)
                            .setReason("test1")
                            .setErrorSource(AtomsProto.ErrorSource.DATA_APP))
                    .build();
    private static final AtomsProto.Atom ATOM_B =
            AtomsProto.Atom.newBuilder()
                    .setAnrOccurred(ANROccurred.newBuilder()
                            .setUid(2000)
                            .setPackageName(PACKAGE_NAME_2)
                            .setReason("test2")
                            .setErrorSource(AtomsProto.ErrorSource.SYSTEM_APP))
                    .build();
    private static final AtomsProto.Atom ATOM_MISMATCH =
            AtomsProto.Atom.newBuilder()
                    .setAnrOccurred(ANROccurred.newBuilder()
                            .setReason("test"))
                    .build();

    // Subject of the test.
    private AnrOccurredConverter mConverter = new AnrOccurredConverter();

    @Test
    public void testConvertAtomsListWithDimensionValues_putsCorrectDataToPersistableBundle()
            throws StatsConversionException {
        List<AtomsProto.Atom> atomsList = Arrays.asList(ATOM_A, ATOM_B);

        SparseArray<AtomFieldAccessor<ANROccurred, ?>> accessorMap =
                mConverter.getAtomFieldAccessorMap();

        PersistableBundle bundle = mConverter.convert(atomsList, null, null, null);

        assertThat(bundle.size()).isEqualTo(4);
        assertThat(bundle.getIntArray(accessorMap.get(UID_FIELD_NUMBER).getFieldName()))
                .asList().containsExactly(1000, 2000).inOrder();
        assertThat(Arrays.asList(
                bundle.getStringArray(accessorMap.get(PACKAGE_NAME_FIELD_NUMBER).getFieldName())))
                .containsExactly(PACKAGE_NAME_1, PACKAGE_NAME_2).inOrder();
        assertThat(bundle.getStringArray(accessorMap.get(REASON_FIELD_NUMBER).getFieldName()))
                .asList().containsExactly("test1", "test2").inOrder();
        assertThat(bundle.getIntArray(accessorMap.get(ERROR_SOURCE_FIELD_NUMBER).getFieldName()))
                .asList().containsExactly(1, 2).inOrder();  // DATA_APP=1, SYSTEM_APP=2
    }

    @Test
    public void testAtomSetFieldInconsistency_throwsException() {
        List<AtomsProto.Atom> atomsList = Arrays.asList(ATOM_A, ATOM_MISMATCH);

        assertThrows(
                StatsConversionException.class,
                () -> mConverter.convert(
                        atomsList,
                        null,
                        null,
                        null));
    }
}
