class DiscordCallback extends RestCallback
{
    ref DiscordChat m_DiscordChat;

    void SetDiscordChat(DiscordChat _DiscordChat)
    {
        m_DiscordChat = _DiscordChat;
    }

    override void OnError(int errorCode)
    {
        m_DiscordChat.m_Log.Log("RestCallback OnError, code " + errorCode.ToString());
    }

    override void OnTimeout()
    {
        m_DiscordChat.m_Log.Log("RestCallback OnTimeout");
    }

    override void OnSuccess(string data, int dataSize)
    {
        m_DiscordChat.m_Log.Log("RestCallback OnSuccess size=" + dataSize.ToString());
    }

    override void OnFileCreated(string fileName, int dataSize)
    {
        m_DiscordChat.m_Log.Log("RestCallback OnFileCreated, file=" + fileName + " size=" + dataSize.ToString());
    }
}
