private void Accept()
{
    //接受连接
    Socket clientSocket = socketSevice.Accept();

    User newUser = new User(clientSocket, Count++);


    userList.Add(newUser);
    //listen
    Thread RecvThread = new Thread(ReceiveMessage);
    RecvThread.IsBackground = true;
    RecvThread.Start(newUser);


    //打印已经连接IP地址
    Console.WriteLine(IPToAddress(clientSocket) + "\t" + "Uid: " + newUser.Uid.ToString() + "\t\t连接");

    //返回UID
    StringWriter sw = new StringWriter();
    JsonWriter writer = new JsonTextWriter(sw);
    writer.WriteStartObject();
    AddProp(ref writer, "command", "login");
    AddProp(ref writer, "UID", newUser.Uid.ToString());
    writer.WriteEndObject();
    writer.Flush();
    newUser.socketObj.Send(Encoding.UTF8.GetBytes(Json2str(ref sw, writer)));




    Accept();
}