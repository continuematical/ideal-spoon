package com.example.star;

import android.content.Context;
import android.util.Log;
import android.widget.Toast;

public class MLOC {
    public static Context appContext;
    public static String userId = "";

    public static String SERVER_HOST = "demo.starrtc.com";
    public static String VOIP_SERVER_URL = SERVER_HOST + ":10086";
    public static String IM_SERVER_URL = SERVER_HOST + ":19903";
    public static String CHATROOM_SERVER_URL = SERVER_HOST + ":19906";
    public static String LIVE_VDN_SERVER_URL = SERVER_HOST + ":19928";
    public static String LIVE_SRC_SERVER_URL = SERVER_HOST + ":19931";
    public static String LIVE_PROXY_SERVER_URL = SERVER_HOST + ":19932";

    public static Boolean AEventCenterEnable = false;

    public static String IM_GROUP_LIST_URL = "http://www.starrtc.com/aec/group/list.php";
    public static String IM_GROUP_INFO_URL = "http://www.starrtc.com/aec/group/members.php";
    public static String LIST_SAVE_URL = "http://www.starrtc.com/aec/list/save.php";
    public static String LIST_DELETE_URL = "http://www.starrtc.com/aec/list/del.php";
    public static String LIST_QUERY_URL = "http://www.starrtc.com/aec/list/query.php";

    public static final int LIST_TYPE_CHATROOM = 0;             //IM 聊天室
    public static final int LIST_TYPE_LIVE = 1;                 //直播
    public static final int LIST_TYPE_LIVE_PUSH = 2;            //直播转推第三方流
    public static final int LIST_TYPE_MEETING = 3;              //会议
    public static final int LIST_TYPE_MEETING_PUSH = 4;         //会议转推第三方流
    public static final int LIST_TYPE_CLASS = 5;                //小班课
    public static final int LIST_TYPE_CLASS_PUSH = 6;           //小班课转推第三方流
    public static final int LIST_TYPE_AUDIO_LIVE = 7;           //音频直播
    public static final int LIST_TYPE_AUDIO_LIVE_PUSH = 8;      //音频直播转推第三方流
    public static final int LIST_TYPE_SUPER_ROOM = 9;           //超级对讲
    public static final int LIST_TYPE_SUPER_ROOM_PUSH = 10;     //超级对讲转推第三方流

    public static final String LIST_TYPE_LIVE_ALL = LIST_TYPE_LIVE + "," + LIST_TYPE_LIVE_PUSH;
    public static final String LIST_TYPE_MEETING_ALL = LIST_TYPE_MEETING + "," + LIST_TYPE_MEETING_PUSH;
    public static final String LIST_TYPE_CLASS_ALL = LIST_TYPE_CLASS + "," + LIST_TYPE_CLASS_PUSH;
    public static final String LIST_TYPE_AUDIO_LIVE_ALL = LIST_TYPE_AUDIO_LIVE + "," + LIST_TYPE_AUDIO_LIVE_PUSH;
    public static final String LIST_TYPE_SUPER_ROOM_ALL = LIST_TYPE_SUPER_ROOM + "," + LIST_TYPE_SUPER_ROOM_PUSH;
    public static final String LIST_TYPE_PUSH_ALL = LIST_TYPE_LIVE_PUSH
            + "," + LIST_TYPE_MEETING_PUSH
            + "," + LIST_TYPE_CLASS_PUSH
            + "," + LIST_TYPE_AUDIO_LIVE_PUSH
            + "," + LIST_TYPE_SUPER_ROOM_PUSH;
    public static Boolean hasLogout = false;

    public static boolean hasNewC2CMsg = false;
    public static boolean hasNewGroupMsg = false;
    public static boolean hasNewVoipMsg = false;
    public static boolean canPickupVoip = true;

    public static boolean deleteGroup = false;

    //show message
    private static Toast mToast;

    public static void showMsg(String str) {
        try {
            if (mToast != null) {
                mToast.setText(str);
                mToast.setDuration(Toast.LENGTH_SHORT);
            } else {
                mToast = Toast.makeText(appContext.getApplicationContext(), str, Toast.LENGTH_SHORT);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void showMsg(Context context, String str) {
        try {
            if (mToast != null) {
                mToast.setText(str);
                mToast.setDuration(Toast.LENGTH_SHORT);
            } else {
                mToast = Toast.makeText(context.getApplicationContext(), str, Toast.LENGTH_SHORT);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    //debug
    private static Boolean debug = true;

    public static void setDebug(Boolean b) {
        debug = b;
    }

    public static void d(String Tag, String msg) {
        if (debug) Log.d("starSDK_demo_" + Tag, msg);
    }
}
