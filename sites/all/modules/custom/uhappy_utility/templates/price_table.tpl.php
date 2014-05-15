<div class="row base">

    <?php if (isset($price_for_1)): ?>
        <div class="col-md-4" data-scrollreveal="enter bottom and move 40px over 0.8s">
            <ul class="plan planone">
                <li class="name">Basic</li>
                <li class="price"><?php print $price_for_1 ?> lei</li>
                <li>5GB Storage</li>
                <li>1GB RAM</li>
                <li>400GB Bandwidth</li>
                <li>10 Email Address</li>
                <li>Forum Support</li>
                <li class="below">
                    <a href="#"><?php print t('Order'); ?></a>
                </li>
            </ul>
        </div>
    <?php endif; ?>

    <?php if (isset($price_for_2)): ?>
        <div class="col-md-4" data-scrollreveal="enter bottom and move 40px over 0.8s">
            <ul class="plan plantwo featured">
            <!-- <ul class="plan planthree"> -->
                <li class="name">Standard</li>
                <li class="price"><?php print $price_for_2 ?> lei</li>
                <li>5GB Storage</li>
                <li>1GB RAM</li>
                <li>400GB Bandwidth</li>
                <li>10 Email Address</li>
                <li>Forum Support</li>
                <li class="below highlighted">
                <!-- <li class="below"> -->
                    <a href="#"><?php print t('Order'); ?></a>
                </li>
            </ul>
        </div>
    <?php endif; ?>

    <div class="col-md-4" data-scrollreveal="enter bottom and move 40px over 0.8s">
        <ul class="plan planthree">
            <li class="name">Advanced</li>
            <!-- <li class="price">$199 / month</li> -->
            <li>50GB Storage</li>
            <li>8GB RAM</li>
            <li>1024GB Bandwidth</li>
            <li>Unlimited Email Address</li>
            <li>Forum Support</li>
            <li class="below">
                <a href="#"><?php print t('Order'); ?></a>
            </li>

        </ul>
    </div>

</div>
