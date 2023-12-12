package com.android.systemui.statusbar.charging;

import android.graphics.Color;
import android.graphics.PointF;
import android.graphics.RuntimeShader;
import android.util.MathUtils;

/**
 * Shader class that renders a distorted ripple for the UDFPS dwell effect.
 * Adjustable shader parameters:
 *  - progress
 *  - origin
 *  - color
 *  - time
 *  - maxRadius
 *  - distortionStrength.
 * See per field documentation for more details.
 *
 * Modeled after frameworks/base/graphics/java/android/graphics/drawable/RippleShader.java.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0010\u0007\n\u0002\b\b\n\u0002\u0018\u0002\n\u0002\b\f\u0018\u0000 \u001f2\u00020\u0001:\u0001\u001fB\u0007\b\u0000\u00a2\u0006\u0002\u0010\u0002R$\u0010\u0005\u001a\u00020\u00042\u0006\u0010\u0003\u001a\u00020\u0004@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0006\u0010\u0007\"\u0004\b\b\u0010\tR$\u0010\u000b\u001a\u00020\n2\u0006\u0010\u0003\u001a\u00020\n@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\f\u0010\r\"\u0004\b\u000e\u0010\u000fR\u001a\u0010\u0010\u001a\u00020\nX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0011\u0010\r\"\u0004\b\u0012\u0010\u000fR$\u0010\u0014\u001a\u00020\u00132\u0006\u0010\u0003\u001a\u00020\u0013@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0015\u0010\u0016\"\u0004\b\u0017\u0010\u0018R$\u0010\u0019\u001a\u00020\n2\u0006\u0010\u0003\u001a\u00020\n@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001a\u0010\r\"\u0004\b\u001b\u0010\u000fR$\u0010\u001c\u001a\u00020\n2\u0006\u0010\u0003\u001a\u00020\n@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001d\u0010\r\"\u0004\b\u001e\u0010\u000f"}, d2 = {"Lcom/android/systemui/statusbar/charging/DwellRippleShader;", "Landroid/graphics/RuntimeShader;", "()V", "value", "", "color", "getColor", "()I", "setColor", "(I)V", "", "distortionStrength", "getDistortionStrength", "()F", "setDistortionStrength", "(F)V", "maxRadius", "getMaxRadius", "setMaxRadius", "Landroid/graphics/PointF;", "origin", "getOrigin", "()Landroid/graphics/PointF;", "setOrigin", "(Landroid/graphics/PointF;)V", "progress", "getProgress", "setProgress", "time", "getTime", "setTime", "Companion"})
public final class DwellRippleShader extends android.graphics.RuntimeShader {
    
    /**
     * Maximum radius of the ripple.
     */
    private float maxRadius = 0.0F;
    
    /**
     * Origin coordinate of the ripple.
     */
    @org.jetbrains.annotations.NotNull()
    private android.graphics.PointF origin;
    
    /**
     * Progress of the ripple. Float value between [0, 1].
     */
    private float progress = 0.0F;
    
    /**
     * Distortion strength between [0, 1], with 0 being no distortion and 1 being full distortion.
     */
    private float distortionStrength = 0.0F;
    
    /**
     * Play time since the start of the effect in seconds.
     */
    private float time = 0.0F;
    
    /**
     * A hex value representing the ripple color, in the format of ARGB
     */
    private int color = 16777215;
    private static final java.lang.String SHADER_UNIFORMS = "uniform vec2 in_origin;\n                uniform float in_time;\n                uniform float in_radius;\n                uniform float in_blur;\n                uniform vec4 in_color;\n                uniform float in_phase1;\n                uniform float in_phase2;\n                uniform float in_distortion_strength;";
    private static final java.lang.String SHADER_LIB = "\n                float softCircle(vec2 uv, vec2 xy, float radius, float blur) {\n                  float blurHalf = blur * 0.5;\n                  float d = distance(uv, xy);\n                  return 1. - smoothstep(1. - blurHalf, 1. + blurHalf, d / radius);\n                }\n\n                float softRing(vec2 uv, vec2 xy, float radius, float blur) {\n                  float thickness_half = radius * 0.25;\n                  float circle_outer = softCircle(uv, xy, radius + thickness_half, blur);\n                  float circle_inner = softCircle(uv, xy, radius - thickness_half, blur);\n                  return circle_outer - circle_inner;\n                }\n\n                vec2 distort(vec2 p, float time, float distort_amount_xy, float frequency) {\n                    return p + vec2(sin(p.y * frequency + in_phase1),\n                                    cos(p.x * frequency * -1.23 + in_phase2)) * distort_amount_xy;\n                }\n\n                vec4 ripple(vec2 p, float distort_xy, float frequency) {\n                    vec2 p_distorted = distort(p, in_time, distort_xy, frequency);\n                    float circle = softCircle(p_distorted, in_origin, in_radius * 1.2, in_blur);\n                    float rippleAlpha = max(circle,\n                        softRing(p_distorted, in_origin, in_radius, in_blur)) * 0.25;\n                    return in_color * rippleAlpha;\n                }\n                ";
    private static final java.lang.String SHADER_MAIN = "vec4 main(vec2 p) {\n                    vec4 color1 = ripple(p,\n                        34 * in_distortion_strength, // distort_xy\n                        0.012 // frequency\n                    );\n                    vec4 color2 = ripple(p,\n                        49 * in_distortion_strength, // distort_xy\n                        0.018 // frequency\n                    );\n                    // Alpha blend between two layers.\n                    return vec4(color1.xyz + color2.xyz\n                        * (1 - color1.w), color1.w + color2.w * (1-color1.w));\n                }";
    private static final java.lang.String SHADER = "uniform vec2 in_origin;\n                uniform float in_time;\n                uniform float in_radius;\n                uniform float in_blur;\n                uniform vec4 in_color;\n                uniform float in_phase1;\n                uniform float in_phase2;\n                uniform float in_distortion_strength;\n                float softCircle(vec2 uv, vec2 xy, float radius, float blur) {\n                  float blurHalf = blur * 0.5;\n                  float d = distance(uv, xy);\n                  return 1. - smoothstep(1. - blurHalf, 1. + blurHalf, d / radius);\n                }\n\n                float softRing(vec2 uv, vec2 xy, float radius, float blur) {\n                  float thickness_half = radius * 0.25;\n                  float circle_outer = softCircle(uv, xy, radius + thickness_half, blur);\n                  float circle_inner = softCircle(uv, xy, radius - thickness_half, blur);\n                  return circle_outer - circle_inner;\n                }\n\n                vec2 distort(vec2 p, float time, float distort_amount_xy, float frequency) {\n                    return p + vec2(sin(p.y * frequency + in_phase1),\n                                    cos(p.x * frequency * -1.23 + in_phase2)) * distort_amount_xy;\n                }\n\n                vec4 ripple(vec2 p, float distort_xy, float frequency) {\n                    vec2 p_distorted = distort(p, in_time, distort_xy, frequency);\n                    float circle = softCircle(p_distorted, in_origin, in_radius * 1.2, in_blur);\n                    float rippleAlpha = max(circle,\n                        softRing(p_distorted, in_origin, in_radius, in_blur)) * 0.25;\n                    return in_color * rippleAlpha;\n                }\n                vec4 main(vec2 p) {\n                    vec4 color1 = ripple(p,\n                        34 * in_distortion_strength, // distort_xy\n                        0.012 // frequency\n                    );\n                    vec4 color2 = ripple(p,\n                        49 * in_distortion_strength, // distort_xy\n                        0.018 // frequency\n                    );\n                    // Alpha blend between two layers.\n                    return vec4(color1.xyz + color2.xyz\n                        * (1 - color1.w), color1.w + color2.w * (1-color1.w));\n                }";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.charging.DwellRippleShader.Companion Companion = null;
    
    public final float getMaxRadius() {
        return 0.0F;
    }
    
    public final void setMaxRadius(float p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.PointF getOrigin() {
        return null;
    }
    
    public final void setOrigin(@org.jetbrains.annotations.NotNull()
    android.graphics.PointF value) {
    }
    
    public final float getProgress() {
        return 0.0F;
    }
    
    public final void setProgress(float value) {
    }
    
    public final float getDistortionStrength() {
        return 0.0F;
    }
    
    public final void setDistortionStrength(float value) {
    }
    
    public final float getTime() {
        return 0.0F;
    }
    
    public final void setTime(float value) {
    }
    
    public final int getColor() {
        return 0;
    }
    
    public final void setColor(int value) {
    }
    
    public DwellRippleShader() {
        super(null, false);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0003\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/charging/DwellRippleShader$Companion;", "", "()V", "SHADER", "", "SHADER_LIB", "SHADER_MAIN", "SHADER_UNIFORMS"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}