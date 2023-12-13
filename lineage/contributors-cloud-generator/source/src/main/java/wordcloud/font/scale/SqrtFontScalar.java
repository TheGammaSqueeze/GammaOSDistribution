package wordcloud.font.scale;

/**
 * Created by kenny on 6/30/14.
 */
public class SqrtFontScalar implements FontScalar {

    private int minFont;
    private int maxFont;

    public SqrtFontScalar(int minFont, int maxFont) {
        this.minFont = minFont;
        this.maxFont = maxFont;
    }

    @Override
    public float scale(int value, int minValue, int maxValue) {
        double leftSpan = Math.sqrt(maxValue) - Math.sqrt(minValue);
        double rightSpan = maxFont - minFont;

        // Convert the left range into a 0-1 range
        double valueScaled = (Math.sqrt(value) - Math.sqrt(minValue)) / leftSpan;

        // Convert the 0-1 range into a value in the right range.
        return (float)(minFont + (valueScaled * rightSpan));
    }

    @Override
    public void reduceBy(int n) {
        minFont -= n;
        maxFont -= n;
    }
}
