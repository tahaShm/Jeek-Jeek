#include "jeekjeek.hpp"
#include "connectors.hpp"
int main(){
	JeekJeek j;
	
	User u("a" , "A" , "1234");
	Jeek jee;
	jee.setText("salam olagh :(");
	jee.addTag("khar");
	jee.addMentioned("a");
	j.signUp("ali" , "Ali" , "12345678");
	j.signUp("taha" , "Taha" , "Taha1378");
	j.signUp("a" , "A" , "1");
	j.logIn("ali" , "12345678");
	j.logIn("taha" , "Taha1378");
	j.logIn("a" , "1");
	j.signUp("aa" , "Aa" , "1a");
	//j.logOut("taha");
	j.addNewJeek(jee , "taha");
	j.addNewJeek(jee , "ali");
	j.searchUser("ali");
	j.signUp("fsdf" , "sdli" , "1234d78");
	j.reJeek("jeekId1" , "a");
	j.like("jeekId3" , "taha");
	j.like("jeekId3" , "ali");
	j.showJeek("jeekId1");
	j.showJeek("jeekId2");
	j.showJeek("jeekId3");
	/*j.addComment("jeekId1","kheyli khari");
	j.addComment("jeekId1","kheyl khari");
	j.addReplyToComment("commentId2", "khodeti");
	//j.showComment(1);
	//j.showReply("replyId1");
	j.addReplyToReply("replyId1", "bazam khari");
	j.showReply("replyId1");
	j.addReplyToReply("replyId2" , "sds");
	j.showReply("replyId1");
	j.showReply("replyId2");
	j.showReply("replyId3");
	j.signUp("fsdf" , "sdli" , "1234d78");
	//j.showReply(1);
	//j.showComment(1);
	j.reJeek("jeekId1");
	//j.showJeek(2);
	j.like("jeekId1");
	//j.dislike(1);
	//j.showJeek(1);
	j.follow("fsdf");
	j.follow("ali");
	j.unfollow("ali");
	j.unfollow("fsdf");
	j.unfollow("ali");
	j.unfollow("fsds");*/
	
}