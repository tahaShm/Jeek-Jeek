<html>
<head>
    <title>Admin login</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
    <style>
        body, html {
            height: 120vh;
            background-repeat: no-repeat;
            background-image: linear-gradient(rgb(104, 145, 162), rgb(12, 97, 33));
            background-image: linear-gradient(rgb(50, 0, 200), rgb(0, 100, 50));

        }

        .card-container.card {
            max-width: 350px;
            padding: 40px 40px;
        }

        .btn {
            font-weight: 700;
            height: 36px;
            -moz-user-select: none;
            -webkit-user-select: none;
            user-select: none;
            cursor: default;
        }

        /*
         * Card component
         */
        .card {
            background-color: #F7F7F7;
            /* just in case there no content*/
            padding: 20px 25px 30px;
            margin: 0 auto 25px;
            margin-top: 50px;
            /* shadows and rounded borders */
            -moz-border-radius: 2px;
            -webkit-border-radius: 2px;
            border-radius: 2px;
            -moz-box-shadow: 0px 2px 2px rgba(0, 0, 0, 0.3);
            -webkit-box-shadow: 0px 2px 2px rgba(0, 0, 0, 0.3);
            box-shadow: 0px 2px 2px rgba(0, 0, 0, 0.3);
        }

        .profile-img-card {
            width: 96px;
            height: 96px;
            margin: 0 auto 10px;
            display: block;
            -moz-border-radius: 50%;
            -webkit-border-radius: 50%;
            border-radius: 50%;
        }

        /*
         * Form styles
         */
        .profile-name-card {
            font-size: 16px;
            font-weight: bold;
            text-align: center;
            margin: 10px 0 0;
            min-height: 1em;
        }

        .reauth-username {
            display: block;
            color: #404040;
            line-height: 2;
            margin-bottom: 10px;
            font-size: 14px;
            text-align: center;
            overflow: hidden;
            text-overflow: ellipsis;
            white-space: nowrap;
            -moz-box-sizing: border-box;
            -webkit-box-sizing: border-box;
            box-sizing: border-box;
        }

        .form-signin #inputusername,
        .form-signin #inputPassword {
            direction: ltr;
            height: 44px;
            font-size: 16px;
        }

        .form-signin input[type=text],
        .form-signin input[type=password],
        .form-signin input[type=text],
        .form-signin button {
            width: 100%;
            display: block;
            margin-bottom: 10px;
            z-index: 1;
            position: relative;
            -moz-box-sizing: border-box;
            -webkit-box-sizing: border-box;
            box-sizing: border-box;
        }

        .form-signin .form-control:focus {
            border-color: rgb(104, 145, 162);
            outline: 0;
            -webkit-box-shadow: inset 0 1px 1px rgba(0,0,0,.075),0 0 8px rgb(104, 145, 162);
            box-shadow: inset 0 1px 1px rgba(0,0,0,.075),0 0 8px rgb(104, 145, 162);
        }

        .btn.btn-signin {
            /*background-color: #4d90fe; */
            background-color: rgb(104, 145, 162);
            /* background-color: linear-gradient(rgb(104, 145, 162), rgb(12, 97, 33));*/
            padding: 0px;
            font-weight: 700;
            font-size: 14px;
            height: 36px;
            -moz-border-radius: 3px;
            -webkit-border-radius: 3px;
            border-radius: 3px;
            border: none;
            -o-transition: all 0.218s;
            -moz-transition: all 0.218s;
            -webkit-transition: all 0.218s;
            transition: all 0.218s;
        }

        .btn.btn-signin:hover,
        .btn.btn-signin:active,
        .btn.btn-signin:focus {
            background-color: rgb(12, 97, 33);
        }

        .forgot-password {
            color: rgb(104, 145, 162);
        }

        .forgot-password:hover,
        .forgot-password:active,
        .forgot-password:focus{
            color: rgb(12, 97, 33);
        }
    </style>
</head>
<body>
<?php $_SESSION['user_login']='' ?>

<div class="container-fluid">
    <form action="<?= base_url(); ?>admin/sign_admin" method="post">
        <div class="container">
            <div class="card card-container">
                <img src="../files/admin.jpg" class="profile-img-card">

                <!--<p id="profile-name" class="profile-name-card"></p>-->
                <!-- <form class="form-signin">

                     <input type="text" id="name" name="name class="form-control" placeholder="User name" required autofocus>
                     <input type="text" id="lname" name="name" class="form-control" placeholder="family name" required>

                     <input type="password" id="Password" class="form-control" placeholder="Password" required>
                     <div id="remember" class="checkbox">
                         <label>
                             <input type="checkbox" value="remember-me"> Remember me
                         </label>
                     </div>
                     <button class="btn btn-lg btn-primary btn-block btn-signin" type="submit">Sign in</button>


                 </form><!-- /form -->

                 <div class="form-group">
                        <h3 style="text-align: center"><span class="label label-info" >username</span></h3>
                        <input type="text" class="form-control" id="name" name="name" placeholder="username" required autofocus>
                    </div>
                    <!--<div class="form-group">
                        <h3 style="text-align: center"><span class="label label-primary">family name</span></h3>
                        <input type="text" class="form-control" id="lname" name="lname" placeholder="family name" required>
                    </div>-->
                    <div class="form-group">
                        <h3 style="text-align: center"><span class="label label-danger">password</span></h3>
                        <input type="password" class="form-control" id="password" name="password" placeholder="password" required>
                    </div>
                    <button type="submit" class="bbtn btn-lg btn-primary btn-block btn-signin">Sign in</button><br>
                </form><br></br>
                <?php
                if(isset($_SESSION['check'])) {
                    if ($_SESSION['check'] == 'err')
                        echo '  <h5 style="color: red">Please enter correct information</h5>';

                }?>
                <br>
                <br>

            </div><!-- /card-container -->
        </div>
</div><!-- /container -->
</body>
</html>

