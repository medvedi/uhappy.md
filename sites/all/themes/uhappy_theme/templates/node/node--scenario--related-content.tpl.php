<?php

/**
 * @file
 *
 *
 * Variables:
 *
 * $node (The node object).
 * $content (The render array for this view mode).
 * $title (Title of the node).
 */

$node_url = ltrim($node_url, '/');
// global $base_path;
// $node_url = str_replace($base_path, '', $node_url);
?>

<div class="col-md-4 col-sm-6 col-xs-12" data-scrollreveal="enter bottom and move 40px over 0.8s">
  <div class="highlighted-block">
    <?php if($content['field_main_image']['#items'][0]['uri']): ?>
      <?php print render($content['field_main_image']); ?>
    <?php endif; ?>

    <div class="highlighted-block-inside">
      <h6><?php print $title; ?></h6>
      <?php print render($content['body']); ?>
      <a class="read-more" href="<?php print  'node/' . $node->nid; ?>"><?php print t("Learn More"); ?></a>
    </div>
  </div>
</div>
