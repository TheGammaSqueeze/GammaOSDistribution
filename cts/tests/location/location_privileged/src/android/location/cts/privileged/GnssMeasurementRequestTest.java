package android.location.cts.privileged;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;

import android.Manifest;
import android.content.Context;
import android.location.GnssMeasurementRequest;
import android.location.LocationManager;
import android.os.Parcel;

import androidx.test.core.app.ApplicationProvider;
import androidx.test.ext.junit.runners.AndroidJUnit4;
import androidx.test.platform.app.InstrumentationRegistry;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;

/**
 * Tests fundamental functionality of {@link GnssMeasurementRequest} class. This includes writing
 * and reading from parcel, and verifying computed values and getters.
 */
@RunWith(AndroidJUnit4.class)
public class GnssMeasurementRequestTest {

    private Context mContext;
    private LocationManager mLocationManager;

    @Before
    public void setUp() throws Exception {
        mContext = ApplicationProvider.getApplicationContext();
        mLocationManager = mContext.getSystemService(LocationManager.class);
        assertNotNull(mLocationManager);

        InstrumentationRegistry.getInstrumentation()
                .getUiAutomation()
                .adoptShellPermissionIdentity(Manifest.permission.LOCATION_HARDWARE);
    }

    @After
    public void tearDown() throws Exception {
        InstrumentationRegistry.getInstrumentation()
                .getUiAutomation()
                .dropShellPermissionIdentity();
    }

    @Test
    public void testGetValues() {
        GnssMeasurementRequest request1 = getTestGnssMeasurementRequest(true);
        assertTrue(request1.isCorrelationVectorOutputsEnabled());
        GnssMeasurementRequest request2 = getTestGnssMeasurementRequest(false);
        assertFalse(request2.isCorrelationVectorOutputsEnabled());
    }

    @Test
    public void testDescribeContents() {
        GnssMeasurementRequest request = getTestGnssMeasurementRequest(true);
        assertEquals(request.describeContents(), 0);
    }

    @Test
    public void testWriteToParcel() {
        GnssMeasurementRequest request = getTestGnssMeasurementRequest(true);

        Parcel parcel = Parcel.obtain();
        request.writeToParcel(parcel, 0);
        parcel.setDataPosition(0);
        GnssMeasurementRequest fromParcel = GnssMeasurementRequest.CREATOR.createFromParcel(parcel);

        assertEquals(request, fromParcel);
    }

    @Test
    public void testEquals() {
        GnssMeasurementRequest request1 = getTestGnssMeasurementRequest(true);
        GnssMeasurementRequest request2 = new GnssMeasurementRequest.Builder(request1).build();
        GnssMeasurementRequest request3 = getTestGnssMeasurementRequest(false);
        assertEquals(request1, request2);
        assertNotEquals(request3, request2);
    }

    private GnssMeasurementRequest getTestGnssMeasurementRequest(boolean correlationVectorOutputs) {
        GnssMeasurementRequest.Builder builder = new GnssMeasurementRequest.Builder();
        builder.setCorrelationVectorOutputsEnabled(correlationVectorOutputs);
        return builder.build();
    }
}
