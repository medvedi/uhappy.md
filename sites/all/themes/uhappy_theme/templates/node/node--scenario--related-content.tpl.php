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
<div class="row">
  <div class="hover-content-block col-md-4 col-sm-4 col-xs-12">
    <a class="hover-link" href="<?php print  'node/' . $node->nid; ?>"></a>
    <div class="hover-content-block-inner">
      <?php if($content['field_main_image']['#items'][0]['uri']): ?>
        <?php print render($content['field_main_image']); ?>
      <?php endif; ?>
      <span class="content">
        <span class="title"><?php print $title; ?></span>
        <span class="text">
          <?php print render($content['body']); ?>
        </span>
      </span>
    </div>
  </div>
</div>