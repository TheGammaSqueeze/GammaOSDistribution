package wordcloud.font;

import java.awt.*;

/**
 * Created by kenny on 7/11/14.
 */
public enum FontWeight {
    PLAIN(Font.PLAIN),
    BOLD(Font.BOLD),
    ITALIC(Font.ITALIC);

    private final int weight;

    FontWeight(int weight) {
        this.weight = weight;
    }

    public int getWeight() {
        return weight;
    }

}
