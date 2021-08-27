<html>
<head>
    <title>Admin</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
    <style>
        .label,.glyphicon { margin-right:5px; }
        .container{
            background-color: orange;
        }
    </style>
</head>
<body>
<?php
if (@$_SESSION['user_login']=='') {
    header("Location:http://localhost/admin"); /* Redirect browser */
    exit;
}
?>
<?php
    if (@$_SESSION['user_login']!='')
    {
    echo '
<div class="container">
    <nav class="navbar navbar-default" role="navigation">
        <!-- Brand and toggle get grouped for better mobile display -->
        <div class="navbar-header">
            <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1">
                <span class="sr-only">Toggle navigation</span> <span class="icon-bar"></span><span
                    class="icon-bar"></span><span class="icon-bar"></span>
            </button>
            <a class="navbar-brand" href="http://www.jquery2dotnet.com">Management</a>
        </div>
        <!-- Collect the nav links, forms, and other content for toggling -->
        <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
            <ul class="nav navbar-nav">
                <li class="active"><a href="#"><span class="glyphicon glyphicon-home"></span>Admin</a></li>
                <li><a href="http://localhost/admin/insert"><span class="glyphicon glyphicon-cog"></span>article settings</a></li>
                <li><a href="http://localhost/admin/insert_user"><span class="glyphicon glyphicon-user"></span>user settings</a></li>

                <li class="dropdown"><a href="#" class="dropdown-toggle" data-toggle="dropdown"><span
                            class="glyphicon glyphicon-search"></span>Search <b class="caret"></b></a>
                    <ul class="dropdown-menu" style="min-width: 300px;">
                        <li>
                            <div class="row">
                                <div class="col-md-12">
                                    <form class="navbar-form navbar-left" role="search">
                                        <div class="input-group">
                                            <input type="text" class="form-control" placeholder="Search" />
                                            <span class="input-group-btn">
                                            <button class="btn btn-primary" type="button">
                                                Go!</button>
                                        </span>
                                        </div>
                                    </form>
                                </div>
                            </div>
                        </li>
                    </ul>
                </li>
            </ul>
            <ul class="nav navbar-nav navbar-right">
                <!--    <li class="dropdown"><a href="#" class="dropdown-toggle" data-toggle="dropdown"><span
                                    class="glyphicon glyphicon-comment"></span>Chats <span class="label label-primary">42</span>
                        </a>
                        <ul class="dropdown-menu">
                            <li><a href="#"><span class="label label-warning">7:00 AM</span>Hi :)</a></li>
                            <li><a href="#"><span class="label label-warning">8:00 AM</span>How are you?</a></li>
                            <li><a href="#"><span class="label label-warning">9:00 AM</span>What are you doing?</a></li>
                            <li class="divider"></li>
                            <li><a href="#" class="text-center">View All</a></li>
                        </ul>
                    </li>
                    <li class="dropdown"><a href="#" class="dropdown-toggle" data-toggle="dropdown"><span
                                    class="glyphicon glyphicon-envelope"></span>Inbox <span class="label label-info">32</span>
                        </a>
                        <ul class="dropdown-menu">
                            <li><a href="#"><span class="label label-warning">4:00 AM</span>Favourites Snippet</a></li>
                            <li><a href="#"><span class="label label-warning">4:30 AM</span>Email marketing</a></li>
                            <li><a href="#"><span class="label label-warning">5:00 AM</span>Subscriber focused email
                                    design</a></li>
                            <li class="divider"></li>
                            <li><a href="#" class="text-center">View All</a></li>
                        </ul>
                    </li>-->
                <li class="dropdown"><a href="#" class="dropdown-toggle" data-toggle="dropdown"><span
                            class="glyphicon glyphicon-user"></span>Setting <b class="caret"></b></a>
                    <ul class="dropdown-menu">
                        <li><a href="http://localhost/admin"><span class="glyphicon glyphicon-off"></span>Logout</a></li>
                    </ul>
                </li>
            </ul>
        </div>
        <!-- /.navbar-collapse -->
    </nav>

        <div class="container">
            <div class="row">
                <div class="col-md-5  toppad  pull-right col-md-offset-3 ">
                    <br>
                    <p id="demo"></p>

                    <script>
                        var d = new Date();
                        document.getElementById("demo").innerHTML = d;
                    </script>
                </div>
                <div class="col-xs-12 col-sm-12 col-md-6 col-lg-6 col-xs-offset-0 col-sm-offset-0 col-md-offset-3 col-lg-offset-3 toppad" >


                    <div class="panel panel-info">
                        <div class="panel-heading">
                            <h3 class="panel-title">ADMIN INFO</h3>
                        </div>
                        <div class="panel-body">
                            <div class="row">
                                <img  src="../../'.$admins[0]['image'].'" align="left">
                                <div class="col-md-9 col-lg-9">
                                    <table class="table table-user-information">
                                        <tbody>
                                        <tr>
                                            <td>Name:</td>
                                            <td>'. $admins[0]['name'].'</td>
                                        </tr>
                                        <tr>
                                            <td>family name:</td>
                                            <td>'. $admins[0]['lname'].'</td>
                                        </tr>
                                        <tr>
                                            <td>password</td>
                                            <td>'. $admins[0]['password'].'</td>               
                                        </tr>
                                        </tbody>
                                    </table>
                                    <a href="http://localhost/category" class="btn btn-primary">back to category</a>
</div>
</div>
</div>
</div>
</div>
</div>
</div>
</div>
 ';
    }
    ?>
</body>
</html>

