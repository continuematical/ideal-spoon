package com.example.star;

import android.app.Activity;
import android.widget.TextView;

public class BaseActivity extends Activity implements IEventListener {
    @Override
    protected void onResume() {
        super.onResume();
        if (findViewById(R.id.loading) != null) {

        }
    }

    //网络请求
    @Override
    public void dispatchEvent(String aEventID, boolean success, Object eventObj) {
        switch (aEventID) {
            case AEvent.AEVENT_VOIP_REV_CALLING:
                break;
            case AEvent.AEVENT_CONN_DEATH:
                MLOC.showMsg(BaseActivity.this, "服务已断开");
                if (findViewById(R.id.loading) != null) {
                    ((TextView) findViewById(R.id.loading)).setText("连接异常，请重新登陆");

                }
        }
    }
}
