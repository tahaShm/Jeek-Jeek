<html>
<head>
    <title>User</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
    <style>
        .label,.glyphicon { margin-right:5px; }
        .container{
            background-color: #0683c9;
        }
    </style>
</head>
<body>
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
                    <h3 class="panel-title">USER INFO</h3>
                </div>
                <div class="panel-body">
                    <div class="row">
                        <img  src="../../<?=$users[0]['image']?>" align="left">
                        <!--<div class="col-xs-10 col-sm-10 hidden-md hidden-lg"> <br>
                          <dl>
                            <dt>DEPARTMENT:</dt>
                            <dd>Administrator</dd>
                            <dt>HIRE DATE</dt>
                            <dd>11/12/2013</dd>
                            <dt>DATE OF BIRTH</dt>
                               <dd>11/12/2013</dd>
                            <dt>GENDER</dt>
                            <dd>Male</dd>
                          </dl>
                        </div>-->
                        <div class=" col-md-9 col-lg-9 ">
                            <table class="table table-user-information">
                                <tbody>
                                <tr>
                                    <td>Name:</td>
                                    <td><?= $users[0]['name']?></td>
                                </tr>
                                <tr>
                                    <td>family name:</td>
                                    <td><?= $users[0]['lname']?></td>
                                </tr>
                                <tr>
                                    <td>password</td>
                                    <td><?= $users[0]['password']?></td>
                                </tr>
                                </tbody>
                            </table>
                            <a href="http://localhost/category/1" class="btn btn-primary">back to category</a>
                            <?php echo '<a href="'.base_url().'/register/update_user/'.$users[0]['id'].'"><span class="glyphicon glyphicon-pencil"></span></a>'?>

                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>
</body>
</html>