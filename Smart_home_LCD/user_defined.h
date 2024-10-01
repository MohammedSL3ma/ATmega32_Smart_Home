
/*
 * user_defined.h
 *
 * Created: 9/18/2024 9:29:40 PM
 *  Author: Mohamed Ali
 */ 
typedef struct user
 {
	 char name[16] ;
	 U8 id ;
	 U8 passkey ;
	}user;
	
	typedef struct room
	{
		U8 fan ;
		U8 light ;
		U8 fan_pin ;
		U8 light_pin ;
		
	}room;