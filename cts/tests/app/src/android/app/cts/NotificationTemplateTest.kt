/*
 * Copyright (C) 2020 The Android Open Source Project
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
package android.app.cts

import android.R
import android.app.Notification
import android.app.PendingIntent
import android.app.Person
import android.app.cts.CtsAppTestUtils.platformNull
import android.content.Intent
import android.graphics.Bitmap
import android.graphics.Canvas
import android.graphics.Color
import android.graphics.drawable.Icon
import android.net.Uri
import android.view.View
import android.widget.ImageView
import android.widget.TextView
import androidx.annotation.ColorInt
import androidx.test.filters.SmallTest
import com.google.common.truth.Truth.assertThat
import org.junit.Assume
import kotlin.test.assertFailsWith

class NotificationTemplateTest : NotificationTemplateTestBase() {

    fun testWideIcon_inCollapsedState_cappedTo16By9() {
        val icon = createBitmap(200, 100)
        val views = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setLargeIcon(icon)
                .createContentView()
        checkIconView(views) { iconView ->
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
            assertThat(iconView.width.toFloat())
                    .isWithin(1f)
                    .of((iconView.height * 16 / 9).toFloat())
        }
    }

    fun testWideIcon_inCollapsedState_canShowExact4By3() {
        val icon = createBitmap(400, 300)
        val views = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setLargeIcon(icon)
                .createContentView()
        checkIconView(views) { iconView ->
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
            assertThat(iconView.width.toFloat())
                    .isWithin(1f)
                    .of((iconView.height * 4 / 3).toFloat())
        }
    }

    fun testWideIcon_inCollapsedState_canShowUriIcon() {
        val uri = Uri.parse("content://android.app.stubs.assets/picture_400_by_300.png")
        val icon = Icon.createWithContentUri(uri)
        val views = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setLargeIcon(icon)
                .createContentView()
        checkIconView(views) { iconView ->
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
            assertThat(iconView.width.toFloat())
                    .isWithin(1f)
                    .of((iconView.height * 4 / 3).toFloat())
        }
    }

    fun testWideIcon_inCollapsedState_neverNarrowerThanSquare() {
        val icon = createBitmap(200, 300)
        val views = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setLargeIcon(icon)
                .createContentView()
        checkIconView(views) { iconView ->
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
            assertThat(iconView.width).isEqualTo(iconView.height)
        }
    }

    fun testWideIcon_inBigBaseState_cappedTo16By9() {
        val icon = createBitmap(200, 100)
        val views = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setLargeIcon(icon)
                .createBigContentView()
        checkIconView(views) { iconView ->
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
            assertThat(iconView.width.toFloat())
                    .isWithin(1f)
                    .of((iconView.height * 16 / 9).toFloat())
        }
    }

    fun testWideIcon_inBigBaseState_canShowExact4By3() {
        val icon = createBitmap(400, 300)
        val views = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setLargeIcon(icon)
                .createBigContentView()
        checkIconView(views) { iconView ->
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
            assertThat(iconView.width.toFloat())
                    .isWithin(1f)
                    .of((iconView.height * 4 / 3).toFloat())
        }
    }

    fun testWideIcon_inBigBaseState_neverNarrowerThanSquare() {
        val icon = createBitmap(200, 300)
        val views = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setLargeIcon(icon)
                .createBigContentView()
        checkIconView(views) { iconView ->
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
            assertThat(iconView.width).isEqualTo(iconView.height)
        }
    }

    fun testWideIcon_inBigPicture_cappedTo16By9() {
        val picture = createBitmap(40, 30)
        val icon = createBitmap(200, 100)
        val views = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setLargeIcon(icon)
                .setStyle(Notification.BigPictureStyle().bigPicture(picture))
                .createBigContentView()
        checkIconView(views) { iconView ->
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
            assertThat(iconView.width.toFloat())
                    .isWithin(1f)
                    .of((iconView.height * 16 / 9).toFloat())
        }
    }

    fun testWideIcon_inBigPicture_canShowExact4By3() {
        val picture = createBitmap(40, 30)
        val icon = createBitmap(400, 300)
        val views = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setLargeIcon(icon)
                .setStyle(Notification.BigPictureStyle().bigPicture(picture))
                .createBigContentView()
        checkIconView(views) { iconView ->
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
            assertThat(iconView.width.toFloat())
                    .isWithin(1f)
                    .of((iconView.height * 4 / 3).toFloat())
        }
    }

    fun testWideIcon_inBigPicture_neverNarrowerThanSquare() {
        val picture = createBitmap(40, 30)
        val icon = createBitmap(200, 300)
        val views = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setLargeIcon(icon)
                .setStyle(Notification.BigPictureStyle().bigPicture(picture))
                .createBigContentView()
        checkIconView(views) { iconView ->
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
            assertThat(iconView.width).isEqualTo(iconView.height)
        }
    }

    fun testWideIcon_inBigText_cappedTo16By9() {
        val icon = createBitmap(200, 100)
        val views = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setLargeIcon(icon)
                .setStyle(Notification.BigTextStyle().bigText("Big\nText\nContent"))
                .createBigContentView()
        checkIconView(views) { iconView ->
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
            assertThat(iconView.width.toFloat())
                    .isWithin(1f)
                    .of((iconView.height * 16 / 9).toFloat())
        }
    }

    fun testWideIcon_inBigText_canShowExact4By3() {
        val icon = createBitmap(400, 300)
        val views = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setLargeIcon(icon)
                .setStyle(Notification.BigTextStyle().bigText("Big\nText\nContent"))
                .createBigContentView()
        checkIconView(views) { iconView ->
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
            assertThat(iconView.width.toFloat())
                    .isWithin(1f)
                    .of((iconView.height * 4 / 3).toFloat())
        }
    }

    fun testWideIcon_inBigText_neverNarrowerThanSquare() {
        val icon = createBitmap(200, 300)
        val views = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setLargeIcon(icon)
                .setStyle(Notification.BigTextStyle().bigText("Big\nText\nContent"))
                .createBigContentView()
        checkIconView(views) { iconView ->
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
            assertThat(iconView.width).isEqualTo(iconView.height)
        }
    }

    fun testBigPictureStyle_populatesExtrasCompatibly() {
        val bitmap = createBitmap(40, 30)
        val uri = Uri.parse("content://android.app.stubs.assets/picture_400_by_300.png")
        val iconWithUri = Icon.createWithContentUri(uri)
        val iconWithBitmap = Icon.createWithBitmap(bitmap)
        val style = Notification.BigPictureStyle()
        val builder = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setStyle(style)

        style.bigPicture(bitmap)
        builder.build().let {
            assertThat(it.extras.getParcelable<Bitmap>(Notification.EXTRA_PICTURE))
                    .isSameInstanceAs(bitmap)
            assertThat(it.extras.get(Notification.EXTRA_PICTURE_ICON)).isNull()
        }

        style.bigPicture(iconWithUri)
        builder.build().let {
            assertThat(it.extras.get(Notification.EXTRA_PICTURE)).isNull()
            assertThat(it.extras.getParcelable<Icon>(Notification.EXTRA_PICTURE_ICON))
                    .isSameInstanceAs(iconWithUri)
        }

        style.bigPicture(iconWithBitmap)
        builder.build().let {
            assertThat(it.extras.getParcelable<Bitmap>(Notification.EXTRA_PICTURE))
                    .isSameInstanceAs(bitmap)
            assertThat(it.extras.get(Notification.EXTRA_PICTURE_ICON)).isNull()
        }
    }

    fun testBigPictureStyle_bigPictureUriIcon() {
        val pictureUri = Uri.parse("content://android.app.stubs.assets/picture_400_by_300.png")
        val pictureIcon = Icon.createWithContentUri(pictureUri)
        val builder = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setStyle(Notification.BigPictureStyle().bigPicture(pictureIcon))
        checkViews(builder.createBigContentView()) {
            val pictureView = requireViewByIdName<ImageView>("big_picture")
            assertThat(pictureView.visibility).isEqualTo(View.VISIBLE)
            assertThat(pictureView.drawable.intrinsicWidth).isEqualTo(400)
            assertThat(pictureView.drawable.intrinsicHeight).isEqualTo(300)
        }
    }

    fun testPromoteBigPicture_withBigPictureUriIcon() {
        val pictureUri = Uri.parse("content://android.app.stubs.assets/picture_400_by_300.png")
        val pictureIcon = Icon.createWithContentUri(pictureUri)
        val builder = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setStyle(Notification.BigPictureStyle()
                        .bigPicture(pictureIcon)
                        .showBigPictureWhenCollapsed(true)
                )
        checkIconView(builder.createContentView()) { iconView ->
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
            assertThat(iconView.width.toFloat())
                    .isWithin(1f)
                    .of((iconView.height * 4 / 3).toFloat())
            assertThat(iconView.drawable.intrinsicWidth).isEqualTo(400)
            assertThat(iconView.drawable.intrinsicHeight).isEqualTo(300)
        }
    }

    fun testPromoteBigPicture_withoutLargeIcon() {
        val picture = createBitmap(40, 30)
        val builder = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setStyle(Notification.BigPictureStyle()
                        .bigPicture(picture)
                        .showBigPictureWhenCollapsed(true)
                )
        checkIconView(builder.createContentView()) { iconView ->
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
            assertThat(iconView.width.toFloat())
                    .isWithin(1f)
                    .of((iconView.height * 4 / 3).toFloat())
            assertThat(iconView.drawable.intrinsicWidth).isEqualTo(40)
            assertThat(iconView.drawable.intrinsicHeight).isEqualTo(30)
        }
        checkIconView(builder.createBigContentView()) { iconView ->
            assertThat(iconView.visibility).isEqualTo(View.GONE)
        }
    }

    fun testPromoteBigPicture_withLargeIcon() {
        val picture = createBitmap(40, 30)
        val icon = createBitmap(80, 65)
        val builder = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setLargeIcon(icon)
                .setStyle(Notification.BigPictureStyle()
                        .bigPicture(picture)
                        .showBigPictureWhenCollapsed(true)
                )
        checkIconView(builder.createContentView()) { iconView ->
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
            assertThat(iconView.width.toFloat())
                    .isWithin(1f)
                    .of((iconView.height * 4 / 3).toFloat())
            assertThat(iconView.drawable.intrinsicWidth).isEqualTo(40)
            assertThat(iconView.drawable.intrinsicHeight).isEqualTo(30)
        }
        checkIconView(builder.createBigContentView()) { iconView ->
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
            assertThat(iconView.width.toFloat())
                    .isWithin(1f)
                    .of((iconView.height * 80 / 65).toFloat())
            assertThat(iconView.drawable.intrinsicWidth).isEqualTo(80)
            assertThat(iconView.drawable.intrinsicHeight).isEqualTo(65)
        }
    }

    fun testPromoteBigPicture_withBigLargeIcon() {
        val picture = createBitmap(40, 30)
        val bigIcon = createBitmap(80, 75)
        val builder = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setStyle(Notification.BigPictureStyle()
                        .bigPicture(picture)
                        .bigLargeIcon(bigIcon)
                        .showBigPictureWhenCollapsed(true)
                )
        checkIconView(builder.createContentView()) { iconView ->
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
            assertThat(iconView.width.toFloat())
                    .isWithin(1f)
                    .of((iconView.height * 4 / 3).toFloat())
            assertThat(iconView.drawable.intrinsicWidth).isEqualTo(40)
            assertThat(iconView.drawable.intrinsicHeight).isEqualTo(30)
        }
        checkIconView(builder.createBigContentView()) { iconView ->
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
            assertThat(iconView.width.toFloat())
                    .isWithin(1f)
                    .of((iconView.height * 80 / 75).toFloat())
            assertThat(iconView.drawable.intrinsicWidth).isEqualTo(80)
            assertThat(iconView.drawable.intrinsicHeight).isEqualTo(75)
        }
        assertThat(builder.build().extras.getParcelable<Bitmap>(Notification.EXTRA_PICTURE))
                .isSameInstanceAs(picture)
    }

    fun testBigPicture_withBigLargeIcon_withContentUri() {
        val iconUri = Uri.parse("content://android.app.stubs.assets/picture_400_by_300.png")
        val icon = Icon.createWithContentUri(iconUri)
        val builder = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setStyle(Notification.BigPictureStyle().bigLargeIcon(icon))
        checkIconView(builder.createBigContentView()) { iconView ->
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
            assertThat(iconView.width.toFloat())
                    .isWithin(1f)
                    .of((iconView.height * 4 / 3).toFloat())
            assertThat(iconView.drawable.intrinsicWidth).isEqualTo(400)
            assertThat(iconView.drawable.intrinsicHeight).isEqualTo(300)
        }
    }

    @SmallTest
    fun testBaseTemplate_hasExpandedStateWithoutActions() {
        val views = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .createBigContentView()
        assertThat(views).isNotNull()
    }

    fun testDecoratedCustomViewStyle_collapsedState() {
        val customContent = makeCustomContent()
        val views = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setCustomContentView(customContent)
                .setStyle(Notification.DecoratedCustomViewStyle())
                .createContentView()
        checkViews(views) {
            // first check that the custom view is actually shown
            val customTextView = requireViewByIdName<TextView>("text1")
            assertThat(customTextView.visibility).isEqualTo(View.VISIBLE)
            assertThat(customTextView.text).isEqualTo("Example Text")

            // check that the icon shows
            val iconView = requireViewByIdName<ImageView>("icon")
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
        }
    }

    fun testDecoratedCustomViewStyle_expandedState() {
        val customContent = makeCustomContent()
        val views = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setCustomBigContentView(customContent)
                .setStyle(Notification.DecoratedCustomViewStyle())
                .createBigContentView()
        checkViews(views) {
            // first check that the custom view is actually shown
            val customTextView = requireViewByIdName<TextView>("text1")
            assertThat(customTextView.visibility).isEqualTo(View.VISIBLE)
            assertThat(customTextView.text).isEqualTo("Example Text")

            // check that the app name text shows
            val appNameView = requireViewByIdName<TextView>("app_name_text")
            assertThat(appNameView.visibility).isEqualTo(View.VISIBLE)

            // check that the icon shows
            val iconView = requireViewByIdName<ImageView>("icon")
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
        }
    }

    fun testCustomViewNotification_collapsedState_isDecorated() {
        val customContent = makeCustomContent()
        val views = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setCustomContentView(customContent)
                .createContentView()
        checkViews(views) {
            // first check that the custom view is actually shown
            val customTextView = requireViewByIdName<TextView>("text1")
            assertThat(customTextView.visibility).isEqualTo(View.VISIBLE)

            assertThat(customTextView.text).isEqualTo("Example Text")

            // check that the icon shows
            val iconView = requireViewByIdName<ImageView>("icon")
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
        }
    }

    fun testCustomViewNotification_expandedState_isDecorated() {
        val customContent = makeCustomContent()
        val views = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setCustomBigContentView(customContent)
                .createBigContentView()
        checkViews(views) {
            // first check that the custom view is actually shown
            val customTextView = requireViewByIdName<TextView>("text1")
            assertThat(customTextView.visibility).isEqualTo(View.VISIBLE)
            assertThat(customTextView.text).isEqualTo("Example Text")

            // check that the app name text shows
            val appNameView = requireViewByIdName<TextView>("app_name_text")
            assertThat(appNameView.visibility).isEqualTo(View.VISIBLE)

            // check that the icon shows
            val iconView = requireViewByIdName<ImageView>("icon")
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
        }
    }

    fun testCustomViewNotification_headsUpState_isDecorated() {
        val customContent = makeCustomContent()
        val views = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setContentTitle("Title")
                .setCustomHeadsUpContentView(customContent)
                .createHeadsUpContentView()
        checkViews(views) {
            // first check that the custom view is actually shown
            val customTextView = requireViewByIdName<TextView>("text1")
            assertThat(customTextView.visibility).isEqualTo(View.VISIBLE)
            assertThat(customTextView.text).isEqualTo("Example Text")

            // check that the icon shows
            val iconView = requireViewByIdName<ImageView>("icon")
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
        }
    }

    @SmallTest
    fun testCallStyle_forIncomingCall_validatesArguments() {
        val namedPerson = Person.Builder().setName("Named Person").build()
        val namelessPerson = Person.Builder().setName("").build()
        assertFailsWith(IllegalArgumentException::class, "person must have a non-empty a name") {
            Notification.CallStyle.forIncomingCall(platformNull(), pendingIntent, pendingIntent)
        }
        assertFailsWith(IllegalArgumentException::class, "person must have a non-empty a name") {
            Notification.CallStyle.forIncomingCall(namelessPerson, pendingIntent, pendingIntent)
        }
        assertFailsWith(NullPointerException::class, "declineIntent is required") {
            Notification.CallStyle.forIncomingCall(namedPerson, platformNull(), pendingIntent)
        }
        assertFailsWith(NullPointerException::class, "answerIntent is required") {
            Notification.CallStyle.forIncomingCall(namedPerson, pendingIntent, platformNull())
        }
        Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setStyle(Notification.CallStyle
                        .forIncomingCall(namedPerson, pendingIntent, pendingIntent))
                .build()
    }

    fun testCallStyle_forIncomingCall_hasCorrectActions() {
        val namedPerson = Person.Builder().setName("Named Person").build()
        val builder = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setStyle(Notification.CallStyle
                        .forIncomingCall(namedPerson, pendingIntent, pendingIntent))
        assertThat(builder.build()).isNotNull()
        val answerText = mContext.getString(getAndroidRString("call_notification_answer_action"))
        val declineText = mContext.getString(getAndroidRString("call_notification_decline_action"))
        val hangUpText = mContext.getString(getAndroidRString("call_notification_hang_up_action"))
        val views = builder.createBigContentView()
        checkViews(views) {
            assertThat(requireViewWithText(answerText).visibility).isEqualTo(View.VISIBLE)
            assertThat(requireViewWithText(declineText).visibility).isEqualTo(View.VISIBLE)
            assertThat(findViewWithText(hangUpText)).isNull()
        }
    }

    fun testCallStyle_forIncomingCall_isVideo_hasCorrectActions() {
        val namedPerson = Person.Builder().setName("Named Person").build()
        val builder = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setStyle(Notification.CallStyle
                        .forIncomingCall(namedPerson, pendingIntent, pendingIntent)
                        .setIsVideo(true))
        val notification = builder.build()
        assertThat(notification).isNotNull()
        assertThat(notification.extras.getBoolean(Notification.EXTRA_CALL_IS_VIDEO)).isTrue()
        val answerText = mContext.getString(
                getAndroidRString("call_notification_answer_video_action"))
        val declineText = mContext.getString(getAndroidRString("call_notification_decline_action"))
        val hangUpText = mContext.getString(getAndroidRString("call_notification_hang_up_action"))
        val views = builder.createBigContentView()
        checkViews(views) {
            assertThat(requireViewWithText(answerText).visibility).isEqualTo(View.VISIBLE)
            assertThat(requireViewWithText(declineText).visibility).isEqualTo(View.VISIBLE)
            assertThat(findViewWithText(hangUpText)).isNull()
        }
    }

    @SmallTest
    fun testCallStyle_forOngoingCall_validatesArguments() {
        val namedPerson = Person.Builder().setName("Named Person").build()
        val namelessPerson = Person.Builder().setName("").build()
        assertFailsWith(IllegalArgumentException::class, "person must have a non-empty a name") {
            Notification.CallStyle.forOngoingCall(platformNull(), pendingIntent)
        }
        assertFailsWith(IllegalArgumentException::class, "person must have a non-empty a name") {
            Notification.CallStyle.forOngoingCall(namelessPerson, pendingIntent)
        }
        assertFailsWith(NullPointerException::class, "hangUpIntent is required") {
            Notification.CallStyle.forOngoingCall(namedPerson, platformNull())
        }
        Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setStyle(Notification.CallStyle.forOngoingCall(namedPerson, pendingIntent))
                .build()
    }

    fun testCallStyle_forOngoingCall_hasCorrectActions() {
        val namedPerson = Person.Builder().setName("Named Person").build()
        val builder = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setStyle(Notification.CallStyle.forOngoingCall(namedPerson, pendingIntent))
        assertThat(builder.build()).isNotNull()
        val answerText = mContext.getString(getAndroidRString("call_notification_answer_action"))
        val declineText = mContext.getString(getAndroidRString("call_notification_decline_action"))
        val hangUpText = mContext.getString(getAndroidRString("call_notification_hang_up_action"))
        val views = builder.createBigContentView()
        checkViews(views) {
            assertThat(findViewWithText(answerText)).isNull()
            assertThat(findViewWithText(declineText)).isNull()
            assertThat(requireViewWithText(hangUpText).visibility).isEqualTo(View.VISIBLE)
        }
    }

    @SmallTest
    fun testCallStyle_forScreeningCall_validatesArguments() {
        val namedPerson = Person.Builder().setName("Named Person").build()
        val namelessPerson = Person.Builder().setName("").build()
        assertFailsWith(IllegalArgumentException::class, "person must have a non-empty a name") {
            Notification.CallStyle.forScreeningCall(platformNull(), pendingIntent, pendingIntent)
        }
        assertFailsWith(IllegalArgumentException::class, "person must have a non-empty a name") {
            Notification.CallStyle.forScreeningCall(namelessPerson, pendingIntent, pendingIntent)
        }
        assertFailsWith(NullPointerException::class, "hangUpIntent is required") {
            Notification.CallStyle.forScreeningCall(namedPerson, platformNull(), pendingIntent)
        }
        assertFailsWith(NullPointerException::class, "answerIntent is required") {
            Notification.CallStyle.forScreeningCall(namedPerson, pendingIntent, platformNull())
        }
        Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setStyle(Notification.CallStyle
                        .forScreeningCall(namedPerson, pendingIntent, pendingIntent))
                .build()
    }

    fun testCallStyle_forScreeningCall_hasCorrectActions() {
        val namedPerson = Person.Builder().setName("Named Person").build()
        val builder = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setStyle(Notification.CallStyle
                        .forScreeningCall(namedPerson, pendingIntent, pendingIntent))
        assertThat(builder.build()).isNotNull()
        val answerText = mContext.getString(getAndroidRString("call_notification_answer_action"))
        val declineText = mContext.getString(getAndroidRString("call_notification_decline_action"))
        val hangUpText = mContext.getString(getAndroidRString("call_notification_hang_up_action"))
        val views = builder.createBigContentView()
        checkViews(views) {
            assertThat(requireViewWithText(answerText).visibility).isEqualTo(View.VISIBLE)
            assertThat(findViewWithText(declineText)).isNull()
            assertThat(requireViewWithText(hangUpText).visibility).isEqualTo(View.VISIBLE)
        }
    }

    fun testCallStyle_hidesVerification_whenNotProvided() {
        val person = Person.Builder().setName("Person").build()
        val builder = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setStyle(Notification.CallStyle
                        .forIncomingCall(person, pendingIntent, pendingIntent))

        val notification = builder.build()
        val extras = notification.extras
        assertThat(extras.containsKey(Notification.EXTRA_VERIFICATION_TEXT)).isFalse()
        assertThat(extras.containsKey(Notification.EXTRA_VERIFICATION_ICON)).isFalse()

        val views = builder.createBigContentView()
        checkViews(views) {
            val textView = requireViewByIdName<TextView>("verification_text")
            assertThat(textView.visibility).isEqualTo(View.GONE)

            val iconView = requireViewByIdName<ImageView>("verification_icon")
            assertThat(iconView.visibility).isEqualTo(View.GONE)
        }
    }

    fun testCallStyle_showsVerification_whenProvided() {
        val person = Person.Builder().setName("Person").build()
        val builder = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setStyle(Notification.CallStyle
                        .forIncomingCall(person, pendingIntent, pendingIntent)
                        .setVerificationIcon(Icon.createWithResource(mContext, R.drawable.ic_info))
                        .setVerificationText("Verified!"))

        val notification = builder.build()
        val extras = notification.extras
        assertThat(extras.getCharSequence(Notification.EXTRA_VERIFICATION_TEXT))
                .isEqualTo("Verified!")
        assertThat(extras.getParcelable<Icon>(Notification.EXTRA_VERIFICATION_ICON)?.resId)
                .isEqualTo(R.drawable.ic_info)

        val views = builder.createBigContentView()
        checkViews(views) {
            val textView = requireViewByIdName<TextView>("verification_text")
            assertThat(textView.visibility).isEqualTo(View.VISIBLE)
            assertThat(textView.text).isEqualTo("Verified!")

            val iconView = requireViewByIdName<ImageView>("verification_icon")
            assertThat(iconView.visibility).isEqualTo(View.VISIBLE)
        }
    }

    fun testCallStyle_ignoresCustomColors_whenNotColorized() {
        Assume.assumeTrue("Test will not run when config disabled",
                mContext.resources.getBoolean(getAndroidRBool(
                        "config_callNotificationActionColorsRequireColorized")))
        val person = Person.Builder().setName("Person").build()
        val builder = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setColor(Color.WHITE)
                .setStyle(Notification.CallStyle
                        .forIncomingCall(person, pendingIntent, pendingIntent)
                        .setAnswerButtonColorHint(Color.BLUE)
                        .setDeclineButtonColorHint(Color.MAGENTA))

        val notification = builder.build()
        assertThat(notification.extras.getInt(Notification.EXTRA_ANSWER_COLOR, -1))
                .isEqualTo(Color.BLUE)
        assertThat(notification.extras.getInt(Notification.EXTRA_DECLINE_COLOR, -1))
                .isEqualTo(Color.MAGENTA)

        val answerText = mContext.getString(getAndroidRString("call_notification_answer_action"))
        val declineText = mContext.getString(getAndroidRString("call_notification_decline_action"))
        val views = builder.createBigContentView()
        checkViews(views) {
            assertThat(requireViewWithText(answerText).bgContainsColor(Color.BLUE)).isFalse()
            assertThat(requireViewWithText(declineText).bgContainsColor(Color.MAGENTA)).isFalse()
        }
    }

    fun testCallStyle_usesCustomColors_whenColorized() {
        val person = Person.Builder().setName("Person").build()
        val builder = Notification.Builder(mContext, NOTIFICATION_CHANNEL_ID)
                .setSmallIcon(R.drawable.ic_media_play)
                .setColorized(true)
                .setColor(Color.WHITE)
                .setStyle(Notification.CallStyle
                        .forIncomingCall(person, pendingIntent, pendingIntent)
                        .setAnswerButtonColorHint(Color.BLUE)
                        .setDeclineButtonColorHint(Color.MAGENTA))

        val notification = builder.build()
        assertThat(notification.extras.getInt(Notification.EXTRA_ANSWER_COLOR, -1))
                .isEqualTo(Color.BLUE)
        assertThat(notification.extras.getInt(Notification.EXTRA_DECLINE_COLOR, -1))
                .isEqualTo(Color.MAGENTA)

        // Setting this flag ensures that createBigContentView allows colorization.
        notification.flags = notification.flags or Notification.FLAG_FOREGROUND_SERVICE
        val answerText = mContext.getString(getAndroidRString("call_notification_answer_action"))
        val declineText = mContext.getString(getAndroidRString("call_notification_decline_action"))
        val views = builder.createBigContentView()
        checkViews(views) {
            // TODO(b/184896890): diagnose/fix flaky bgContainsColor method
            assertThat(requireViewWithText(answerText).bgContainsColor(Color.BLUE)) // .isTrue()
            assertThat(requireViewWithText(declineText).bgContainsColor(Color.MAGENTA)) // .isTrue()
        }
    }

    private fun View.bgContainsColor(@ColorInt color: Int): Boolean {
        val background = background ?: return false
        val bitmap = createBitmap(width, height)
        val canvas = Canvas(bitmap)
        background.draw(canvas)
        val maskedColor = color and 0x00ffffff
        for (x in 0 until bitmap.width) {
            for (y in 0 until bitmap.height) {
                if (bitmap.getPixel(x, y) and 0x00ffffff == maskedColor) {
                    return true
                }
            }
        }
        return false
    }

    private val pendingIntent by lazy {
        PendingIntent.getBroadcast(mContext, 0, Intent("test"), PendingIntent.FLAG_IMMUTABLE)
    }

    companion object {
        val TAG = NotificationTemplateTest::class.java.simpleName
        const val NOTIFICATION_CHANNEL_ID = "NotificationTemplateTest"
    }
}