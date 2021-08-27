<!DOCTYPE html>
<html lang="en">
<head>
    <title>User Log in</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
    <style>
        .error {color: #FF0000;}
        heade{
            background-color: #2e8ece;
        }
        table {
            font-family: arial, sans-serif;
            border-collapse: collapse;
            width: 100%;
        }
        *Contact sectiom*/
        .content-header{
            font-family: 'Oleo Script', cursive;
            color:#fcc500;
            font-size: 45px;
        }

        .section-content{
            text-align: center;

        }
        #contact{

            font-family: 'Teko', sans-serif;
            padding-top: 60px;
            width: 100%;
            width: 100vw;
            height: 800px;
            background: #3a6186; /* fallback for old browsers */
            background: -webkit-linear-gradient(to left, saddlebrown ,#66512c); /* Chrome 10-25, Safari 5.1-6 */
            background: linear-gradient(to left, #f89406 , #97310e); /* W3C, IE 10+/ Edge, Firefox 16+, Chrome 26+, Opera 12+, Safari 7+ */

            color : #fff;
        }
        .contact-section{
            padding-top: 40px;
        }
        .contact-section .col-md-6{
            width: 50%;
        }

        .form-line{
            border-right: 1px solid #B29999;
        }

        .form-group{
            margin-top: 10px;
        }
        label{
            font-size: 1.3em;
            line-height: 1em;
            font-weight: normal;
        }
        .form-control{
            font-size: 1.3em;
            color: #080808;
        }
        textarea.form-control {
            height: 135px;
            /* margin-top: px;*/
        }

        .submit{
            font-size: 1.1em;
            float: right;
            width: 150px;
            background-color: transparent;
            color: #fff;

        }
        table {
            font-family: arial, sans-serif;
            border-collapse: collapse;
            width: 100%;
        }

        td, th {
            border: 1px solid purple;
            text-align: left;
            padding: 8px;
        }

        tr:nth-child(even) {
            background-color: deeppink;
        }
    </style>
</head>
<body>
<div class="container-fluid">
    <br>
    <?php
        $_SESSION['image']='';

    // define variables and set to empty values
    $nameErr = $passErr =$familyErr = "";
    $name = $family= $pass = "";

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        if (empty($_POST["nam"])) {
            $nameErr = "Name is required";
        } else {
            $name = test_input($_POST["name"]);
            // check if name only contains letters and whitespace
            if (!preg_match("/^[a-zA-Z ]*$/",$name)) {
                $nameErr = "Only letters and white space allowed";
            }
        }

        if (empty($_POST["family"])) {
            $familyErr = "family name is required";
        } else {
            $family= test_input($_POST["family"]);

        }

        if (empty($_POST["pass"])) {
            $passErr = "password is required";
        } else {
            $pass = test_input($_POST["pass"]);

        }


    }

    function test_input($data) {
        $data = trim($data);
        $data = stripslashes($data);
        $data = htmlspecialchars($data);
        return $data;
    }
    ?>
    <section id="contact">
        <div class="section-content">
            <h1 class="section-header">User Log In</h1>
        </div>
        <div class="contact-section">
            <div class="container">

        <form action="<?= base_url(); ?>register/login" method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
            <div class="form-group">
                <h3 style="text-align: center"><span class="label label-info" >username</span></h3>
                <input type="text" class="form-control" id="name" name="name" placeholder="type Your name">
                <h4><span class="label label-warning"><?php echo $nameErr;?></span></h4>
                <br><br>
            </div>
            <div class="form-group">
                <h3 style="text-align: center"><span class="label label-primary">family name</span></h3>
                <input type="text" class="form-control" id="lname" name="lname"  placeholder="type Your family name">
                <h4><span class="label label-warning"><?php echo $familyErr;?></span></h4>
                <br><br>
            </div>
            <div class="form-group">
                <h3 style="text-align: center"><span class="label label-danger">password</span></h3>
                <input type="password" class="form-control" id="password" name="password"  placeholder="type Your password">
                <h4><span class="label label-warning"><?php echo $passErr;?></span></h4>
                <br><br>
            </div>
            <button type="submit" class="btn btn-success"><i class="fa fa-paper-plane" aria-hidden="true">Go</button><br>
        </form><br></br>
            </div>
        </div>
    </section>
</div>
</body>
</html>
