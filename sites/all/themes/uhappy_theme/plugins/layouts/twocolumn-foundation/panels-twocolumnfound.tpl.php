<?php
/**
 * @file
 * Template for a 2 column panel layout.
 *
 * This template provides a very simple "one column" panel display layout.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   $content['one']: First column
 *   $content['two']: Second column.
 */
?>
<div class="panel-two-column clearfix" <?php if (!empty($css_id)): print "id=\"$css_id\""; endif; ?>>
  <?php if ($content['one'] OR $content['two']): ?>
  <div class="row">
      <?php if (isset($content['one']) && $content['one']): ?>
        <div class="col-first col-md-9 col-sm-8 col-xs-12">
          <?php print $content['one']; ?>
        </div>
      <?php endif; ?>
      <?php if (isset($content['two']) && $content['two']): ?>
        <div class="col-second col-md-3 col-sm-4 col-xs-12">
          <?php print $content['two']; ?>
        </div>
      <?php endif; ?>
  </div>
  <?php endif; ?>
</div>
