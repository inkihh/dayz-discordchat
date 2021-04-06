class DiscordChat
{
	protected static ref DiscordChat s_Instance;

	static const string m_ProfilePath = "$profile:DiscordChat";
	static const string m_ConfigFile = m_ProfilePath + "/settings.json";

	ref inki_Settings m_Settings;
	ref inki_Logger m_Log;

	void DiscordChat()
	{
		MakeDirectory(m_ProfilePath);

		m_Settings = new inki_Settings(m_ConfigFile);
		m_Log = new inki_Logger;

		if (!m_Settings.IsLoaded())
		{
			Print("[DiscordChat] Settings incomplete. Please check $profile:DiscordChat/settings.json");
			Print("[DiscordChat] If it didn't exist at all, an empty one was created right now.");
		}
		else
		{
			Print("[DiscordChat] Ready.");
		}
	}

	static DiscordChat GetInstance()
	{
		if (!s_Instance) s_Instance = new DiscordChat();
		return s_Instance;
	}

	void OnEvent(EventType eventTypeId, Param params)
	{
		if(!m_Settings.IsLoaded()) return;

		ChatMessageEventParams chat_params = ChatMessageEventParams.Cast(params);

		string Username = chat_params.param2;
		string Message = chat_params.param3;

		m_Log.Log("Chat: <" + Username + "> " + Message);

		DiscordCallback Cbxcb = new DiscordCallback;
		Cbxcb.SetDiscordChat(this);

		RestContext Ctx = GetRestApi().GetRestContext("https://discord.com/api/webhooks/" + m_Settings.GetId() + "/" + m_Settings.GetToken() + "/slack");
		Ctx.SetHeader("application/json");
		Ctx.POST(Cbxcb, "", "{\"text\": \"<" +  Username + "> " + Message + "\"}");
	}
}
