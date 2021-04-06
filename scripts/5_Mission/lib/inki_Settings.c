class inki_Settings
{
	private string id = "";
	private string token = "";

	[NonSerialized()]
	private bool m_IsLoaded;

	void inki_Settings(string settingsFilePath)
	{
		this.m_IsLoaded = this.Load(settingsFilePath) && this.id && this.token;
	}

	bool Load(string settingsFilePath)
	{
		if (FileExist(settingsFilePath))
		{
			JsonFileLoader<inki_Settings>.JsonLoadFile(settingsFilePath, this);
			return true;
		}

		JsonFileLoader<inki_Settings>.JsonSaveFile(settingsFilePath, this);
		return false;
	}

	bool IsLoaded()
	{
		return this.m_IsLoaded;
	}

	string GetId()
	{
		return this.id;
	}

	string GetToken()
	{
		return this.token;
	}
}
