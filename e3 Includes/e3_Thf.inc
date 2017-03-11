|----------------------------------------------------------------|
|- THF.inc ( designed to work with e3.mac )	                    -|
|- Written by Muergan									        -|
|----------------------------------------------------------------|
|- Contains various events for The Hidden Forest Server			-|
|----------------------------------------------------------------|

|---------------THF Forest Gate-----------------|

#event thfgate "<#1#> thfgate"
#event thfgate "you tell your party, 'thfgate'"
#event thfgate "#1# tells the group, 'thfgate'"
#event thfgate "#1# tells you, 'thfgate'"
sub Event_thfgate
	 
		/if (${FindItem[=Charm of Queen Adrianne].ID}) {
				/call e3_Cast ${Me.ID} "Charm of Queen Adrianne"
			} else /if (${FindItem[=Advanced Charm of Queen Adrianne].ID}) {
				/call e3_Cast ${Me.ID} "Advanced Charm of Queen Adrianne" 
			} else /if (${FindItem[=Magical Charm of Queen Adrianne].ID}) {
				/call e3_Cast ${Me.ID} "Magical Charm of Queen Adrianne" 
			} else /if (${FindItem[=Advanced Magical Charm of Queen Adrianne].ID}) {
				/call e3_Cast ${Me.ID} "Advanced Magical Charm of Queen Adrianne" 
			} else /if (${FindItem[=Superior Magical Charm of Queen Adrianne].ID}) {
				/call e3_Cast ${Me.ID} "Superior Magical Charm of Queen Adrianne" 
			} else /if (${FindItem[=Exceptional Charm of Queen Adrianne].ID}) {
				/call e3_Cast ${Me.ID} "Exceptional Charm of Queen Adrianne" 
			} else /if (${FindItem[=Exquisite Charm of Queen Adrianne].ID}) {
				/call e3_Cast ${Me.ID} "Exquisite Charm of Queen Adrianne" 
		}
	
/return

|---------------Hidden Vale Gate-----------------|

#event valegate "<#1#> valegate"
#event valegate "you tell your party, 'valegate'"
#event valegate "#1# tells the group, 'valegate'"
#event valegate "#1# tells you, 'valegate'"
sub Event_valegate
	 
		
/if (${FindItem[=Token of the Vale].ID}) {
				/call e3_Cast ${Me.ID} "Token of the Vale"
}
	
/return


|---------------Healing Automation-----------------|

#event healbot "<#1#> healbot"
#event healbot "you tell your party, 'healbot'"
#event healbot "#1# tells the group, 'healbot'"
#event healbot "#1# tells you, 'healbot'"
sub Event_healbot

/if (${FindItem[=A Collapsed Automation I].ID}) {
				/call e3_Cast ${Me.ID} "A Collapsed Automation I"
}
	 
	
/return


|---------------Healing Automation Auto-Summon-----------------|

sub auto_healbot


/if (${autohealbot} && ${FindItem[=A Collapsed Automation I].ID}) {
				/call e3_Cast ${Me.ID} "A Collapsed Automation I"
}
	 
/Return



|-------------- Gather Mana Items -----------------|

Sub check_GatherMana

/if (${Me.PctMana} < 60 && ${Me.PctHPs} > 35) {
	/if (${Me.Combat} && ${Select[${Me.Class.ShortName},BST,PAL,RNG,SHD]}) {
		/return	
	} else /if (${Me.PctMana} < 20 && ${FindItemCount[Fire Crystal Wristguard]} && ${FindItem[Fire Crystal Wristguard].Timer}==0) {
		/call e3_Cast 0 "Fire Crystal Wristguard" 
	} else /if (${Me.PctMana} < 30 && ${FindItemCount[Powerful Silk Slippers]} && ${FindItem[Powerful Silk Slippers].Timer}==0) {
		/call e3_Cast 0 "Powerful Silk Slippers" 
	} else /if (${Me.PctMana} < 40 && ${FindItemCount[Silver Chains]} && ${FindItem[Silver Chains].Timer}==0 &&  !${FindItemCount[Powerful Silk Slippers]}) {
		/call e3_Cast 0 "Silver Chains" 
	} else /if (${Me.PctMana} < 55 && ${FindItemCount[Orb of Spirits]} && ${FindItem[Orb of Spirits].Timer}==0 &&  !${FindItemCount[Powerful Silk Slippers]}) {
		/call e3_Cast 0 "Orb of Spirits" 
	}
}	
		
/Return		
		
		
	

Sub Thf_Setup
/if (${Debug}) /echo |- Thf_Setup ==>
	
	/call INItoVar "${Character_Ini},THF,Auto-HealBot (On/Off)" autohealbot bool outer	
	
	
/if (${Debug}) /echo <== Thf_Setup -|
/return



Sub Thf_Background_Events


/return


Sub thf_Aliases
/if (${Debug} || ${Debug_Thf}) /echo |- thf_Aliases ==>

	/squelch /alias /thfgate /bc thfgate
	/squelch /alias /valegate /bc valegate
	/squelch /alias /healbot /bc healbot


/if (${Debug} || ${Debug_Thf}) /echo <== thf_Aliases -|
/return

SUB THF_CharacterSettings
/if (${Debug}) /echo |- THF_CharacterSettings ==>

	
	/call WriteToIni "${Character_Ini},THF,Auto-HealBot (On/Off)"


/if (${Debug}) /echo <== THF_CharacterSettings -|
/RETURN