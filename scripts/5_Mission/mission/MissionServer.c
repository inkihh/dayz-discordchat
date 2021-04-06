modded class MissionServer
{
	DiscordChat m_DiscordChat;

	void MissionServer()
	{
		m_DiscordChat = DiscordChat.GetInstance();
	}
	
	override void OnEvent(EventType eventTypeId, Param params)
	{
		if(eventTypeId == ChatMessageEventTypeID) 
		{
			if(m_DiscordChat.m_Settings.IsLoaded())	m_DiscordChat.OnEvent(eventTypeId, params);
		}

		super.OnEvent(eventTypeId, params);
	}
}