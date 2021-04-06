class inki_Logger
{
    static const string m_LogPath = DiscordChat.m_ProfilePath + "/log";
    static const string m_LogFile = m_LogPath + "/main.txt";

    void Log(string message)
    {
        FileHandle file = OpenFile(m_LogFile, FileMode.APPEND);

        if (file)
        {
            string timestamp = inki_Helper.GetTimestamp();
            FPrintln(file, "[" + timestamp + "] " + message.Trim());
            CloseFile(file);
        }
        else
        {
            Print("[DiscordChat] Could not create logfile " + m_LogFile);
        }
    }
}


