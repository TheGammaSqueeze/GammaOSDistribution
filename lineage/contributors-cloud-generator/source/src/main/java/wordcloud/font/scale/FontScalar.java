package wordcloud.font.scale;

/**
 * Created by kenny on 6/30/14.
 */
public interface FontScalar {
    float scale(int n, int minValue, int maxValue);
    void reduceBy(int n);
}
