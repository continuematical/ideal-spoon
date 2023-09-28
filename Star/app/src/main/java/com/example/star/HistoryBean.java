package com.example.star;

//历史直播
public class HistoryBean {
    private int id = 0;
    private String type = "";
    private String conversationID = "";
    private int newMsgCount = 0;

    private String lastMsg = "";
    private String lastTime = "";

    private String groupName = "";
    private String groupCreatedID = "";

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getConversationID() {
        return conversationID;
    }

    public void setConversationID(String conversationID) {
        this.conversationID = conversationID;
    }

    public int getNewMsgCount() {
        return newMsgCount;
    }

    public void setNewMsgCount(int newMsgCount) {
        this.newMsgCount = newMsgCount;
    }

    public String getLastMsg() {
        return lastMsg;
    }

    public void setLastMsg(String lastMsg) {
        this.lastMsg = lastMsg;
    }

    public String getLastTime() {
        return lastTime;
    }

    public void setLastTime(String lastTime) {
        this.lastTime = lastTime;
    }

    public String getGroupName() {
        return groupName;
    }

    public void setGroupName(String groupName) {
        this.groupName = groupName;
    }

    public String getGroupCreatedID() {
        return groupCreatedID;
    }

    public void setGroupCreatedID(String groupCreatedID) {
        this.groupCreatedID = groupCreatedID;
    }
}
