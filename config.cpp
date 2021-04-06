class CfgPatches
{
	class DiscordChat
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts"
		};
	};   
};

class CfgMods
{
	class DiscordChat
	{
		dir = "inkihh\DiscordChat";
		picture = "";
		action = "";
		hideName = 0;
		hidePicture = 0;
		name = "DiscordChat";
		credits = "";
		author = "inkihh";
		authorID = "0";
		version = "1";
		extra = 0;
		type = "mod";

		dependencies[] =
		{
			"Mission"
		};

		class defs
		{
			class missionScriptModule
			{
				value="";
				files[] =
				{
					"inkihh\DiscordChat\scripts\5_Mission"
				};
			};
		};
	};
};
