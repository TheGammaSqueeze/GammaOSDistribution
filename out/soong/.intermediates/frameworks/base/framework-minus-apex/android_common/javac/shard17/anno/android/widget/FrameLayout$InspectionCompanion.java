package android.widget;

import android.R;
import android.view.inspector.InspectionCompanion;
import android.view.inspector.PropertyMapper;
import android.view.inspector.PropertyReader;
import java.lang.Override;

/**
 * Inspection companion for {@link FrameLayout}.
 *
 * Generated by {@link android.processor.view.inspector.InspectionCompanionGenerator}
 * on behalf of {@link android.processor.view.inspector.PlatformInspectableProcessor}.
 */
public final class FrameLayout$InspectionCompanion implements InspectionCompanion<FrameLayout> {
    /**
     * Guards against reading properties before mapping them.
     */
    private boolean mPropertiesMapped = false;

    /**
     * Property ID of {@code measureAllChildren}.
     */
    private int mMeasureAllChildrenId;

    @Override
    public void mapProperties(PropertyMapper propertyMapper) {
        mMeasureAllChildrenId = propertyMapper.mapBoolean("measureAllChildren", R.attr.measureAllChildren);
        mPropertiesMapped = true;
    }

    @Override
    public void readProperties(FrameLayout node, PropertyReader propertyReader) {
        if (!mPropertiesMapped) {
            throw new InspectionCompanion.UninitializedPropertyMapException();
        }
        propertyReader.readBoolean(mMeasureAllChildrenId, node.getMeasureAllChildren());
    }
}
