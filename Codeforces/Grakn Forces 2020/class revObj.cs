void UserExit(User user)
{
    Console.WriteLine(IPToAddress(user.socketObj) + "\t" + "Uid: " + user.Uid.ToString() + "\t\t退出");
    user.exited = true;

    DateTime time = DateTime.Now;

    StringWriter sw = new StringWriter();
    JsonWriter writer = new JsonTextWriter(sw);
    writer.WriteStartObject();
    AddProp(ref writer, "command", "notification");
    AddProp(ref writer, "text", user.nickname + "离开了聊天室");
    AddProp(ref writer, "date", time.ToString());
    writer.WriteEndObject();
    writer.Flush();

    string jsonText = Json2str(ref sw, writer);

    userList.Remove(user);
    foreach (User user1 in userList)
    {
        BroadcastUserList(user1);
        user1.socketObj.Send(Encoding.UTF8.GetBytes(jsonText));
    }
}