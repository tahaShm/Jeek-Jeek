<html>
<head>
    <title>Articles</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
    <script src="../../../include/js/bootstrap.min.js"></script>
    <script src="../../../include/js/jquery-3.2.1.js"></script>
    <script src="../../../include/js/article.js"></script>

    <link rel="stylesheet" href="../../../include/css/style_article.css">
    <script>
        function init() {
            window.addEventListener('scroll', function(e){
                var distanceY = window.pageYOffset || document.documentElement.scrollTop,
                    shrinkOn = 300,
                    header = document.querySelector("header");
                if (distanceY > shrinkOn) {
                    classie.add(header,"smaller");
                } else {
                    if (classie.has(header,"smaller")) {
                        classie.remove(header,"smaller");
                    }
                }
            });
        }
        window.onload = init();
    </script>
</head>



<body>
<?php
$_SESSION['ad']='false';
?>
<div id="wrapper">
   <header>
        <div class="container clearfix">
            <h1 id="logo">
                <div><?= $contents[0]['title']?></div>
            </h1>
        </div>
    </header>
    <div id="main">
        <div id="content">
            <img src="<?=$contents[0]['image']?>" style="width: 300px;height: 200px" >
            <section>
                <div class="container">
                    <p><?=$contents[0]['text']?></p>
                </div>
            </section>



        </div>
    </div><!-- #main -->

    <footer>
        <div id="info-bar">
            <div class="container clearfix">
                <span class="all-tutorials"><a href="http://localhost/category/1">← back to home page</a></span>
                   </div>
        </div><!-- /#top-bar -->
    </footer><!-- /footer -->



</div><!-- /#wrapper -->
</body>
</html>
